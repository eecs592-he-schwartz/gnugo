/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 * This is GNU Go, a Go program. Contact gnugo@gnu.org, or see       *
 * http://www.gnu.org/software/gnugo/ for more information.          *
 *                                                                   *
 * Copyright 1999, 2000, 2001, 2002 and 2003                         *
 * by the Free Software Foundation.                                  *
 *                                                                   *
 * This program is free software; you can redistribute it and/or     *
 * modify it under the terms of the GNU General Public License as    *
 * published by the Free Software Foundation - version 2             *
 *                                                                   *
 * This program is distributed in the hope that it will be useful,   *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of    *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the     *
 * GNU General Public License in file COPYING for more details.      *
 *                                                                   *
 * You should have received a copy of the GNU General Public         *
 * License along with this program; if not, write to the Free        *
 * Software Foundation, Inc., 59 Temple Place - Suite 330,           *
 * Boston, MA 02111, USA.                                            *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include "board.h"
#include "hash.h"
#include "random.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



/*
 * This file, together with engine/hash.h implements hashing of go positions
 * using a method known as Zobrist hashing.  See the Texinfo documentation
 * (Reading/Hashing) for more information.  
 */


/* Random values for the hash function. */
static Hash_data  white_hash_ng[BOARDMAX];
static Hash_data  black_hash_ng[BOARDMAX];
static Hash_data  ko_hash_ng[BOARDMAX];

static struct init_struct {
  Hash_data  *array;
  int         array_size;
} hash_init_values[] = {
  {white_hash_ng, BOARDMAX},
  {black_hash_ng, BOARDMAX},
  {ko_hash_ng,    BOARDMAX}
};


/*
 * Initialize the entire hash and transposition table system.
 *
 * This should only be called once, and before calling any other 
 * functions in this file.
 */

void
hash_ng_init(void)
{
  static int  is_initialized = 0;
  Hash_data  *array;
  int         size;
  unsigned    i;
  int         j;
  
  if (is_initialized)
    return;
  
#if TRACE_READ_RESULTS
  /* We need consistent hash values when this option is enabled. */
  gg_srand(1);
#endif
  
  for (i = 0; 
       i < sizeof(hash_init_values) / sizeof(struct init_struct);
       i++) {
    array = hash_init_values[i].array;
    size  = hash_init_values[i].array_size;

    for (j = 0; j < size; j++)
      hashdata_init(array[j], gg_urand(), gg_urand()); 
  }

  is_initialized = 1;
}


/* ================================================================ */


static int is_initialized = 0;


/* Random values for the hash function.  For stones and ko position. */
static Hashvalue white_hash[BOARDMAX][NUM_HASHVALUES];	
static Hashvalue black_hash[BOARDMAX][NUM_HASHVALUES];	
static Hashvalue ko_hash[BOARDMAX][NUM_HASHVALUES];


/* Get a random Hashvalue, where all bits are used. */
static Hashvalue
hash_rand(void)
{
  int i;
  Hashvalue h = 0;

  for (i = 0; 32*i < (int) (CHAR_BIT*sizeof(Hashvalue)); i++)
    h |= (Hashvalue) gg_urand() << 32*i;

  return h;
}


/*
 * Initialize the entire hash system.
 */

void
hash_init(void)
{
  int pos;
  int i;
  struct gg_rand_state state;

  if (is_initialized)
    return;
  
  /* Since the hash initialization consumes a varying number of random
   * numbers depending on the size of the Hashvalue type, we save the
   * state of the random generator now and restore it afterwards.
   */
  gg_get_rand_state(&state);
  
#if TRACE_READ_RESULTS
  /* We need consistent hash values when this option is enabled. */
  gg_srand(1);
#endif
  
  for (i = 0; i < NUM_HASHVALUES; i++)
    for (pos = BOARDMIN; pos < BOARDMAX; pos++) {
      /* Note: We initialize _all_ positions, not just those on board.
       * This way we don't have to worry about changing board sizes.
       */
      black_hash[pos][i] = hash_rand();
      white_hash[pos][i] = hash_rand();
      ko_hash[pos][i]    = hash_rand();
    }

  gg_set_rand_state(&state);
  
  is_initialized = 1;
}


/* ---------------------------------------------------------------- */

/* Calculate the compactboard and the hashvalues in one function.
 * They are always used together and it saves us a loop and a function 
 * call.
 */

void 
hashdata_recalc(Hash_data *target, Intersection *p, int ko_pos)
{
  int pos;
  int i;

  for (i = 0; i < NUM_HASHVALUES; i++)
    target->hashval[i] = 0;
  for (pos = BOARDMIN; pos < BOARDMAX; pos++) {
    if (!ON_BOARD(pos))
      continue;
    switch (p[pos]) {
      default:
      case EMPTY: 
	break;
      case WHITE:
        for (i = 0; i < NUM_HASHVALUES; i++)
	  target->hashval[i] ^= white_hash[pos][i];
	break;
      case BLACK:
        for (i = 0; i < NUM_HASHVALUES; i++)
	  target->hashval[i] ^= black_hash[pos][i];
	break;
    }

  }

  if (ko_pos != 0)
    for (i = 0; i < NUM_HASHVALUES; i++)
      target->hashval[i] ^= ko_hash[ko_pos][i];
}


/*
 * Set or remove ko in the hash value and hash position.
 */

void
hashdata_invert_ko(Hash_data *hd, int pos)
{
  int i;
  for (i = 0; i < NUM_HASHVALUES; i++)
    hd->hashval[i] ^= ko_hash[pos][i];
}



/*
 * Set or remove a stone of COLOR at pos in a Hash_data.
 */

void
hashdata_invert_stone(Hash_data *hd, int pos, int color)
{
  int k;

  if (color == BLACK) {
    for (k = 0; k < NUM_HASHVALUES; k++)
      hd->hashval[k] ^= black_hash[pos][k];
  }
  else if (color == WHITE) {
    for (k = 0; k < NUM_HASHVALUES; k++)
      hd->hashval[k] ^= white_hash[pos][k];
  }
}


int
hashdata_compare(Hash_data *hd1, Hash_data *hd2)
{
  int rc = 0;
  int i;

  for (i = 0; i < NUM_HASHVALUES; i++)
    if (hd1->hashval[i] != hd2->hashval[i]) 
      rc = 2;
  if (rc == 2 && i > 0)
    stats.hash_collisions++;

  return rc;
}

/* Compute hash value to identify the goal area. */
Hash_data
goal_to_hashvalue(const char *goal)
{
  int i, pos;
  Hash_data return_value;
  for (i = 0; i < NUM_HASHVALUES; i++)
    return_value.hashval[i] = 0;
  for (pos = BOARDMIN; pos < BOARDMAX; pos++)
    if (ON_BOARD(pos) && goal[pos])
      for (i = 0; i < NUM_HASHVALUES; i++) 
	return_value.hashval[i] += white_hash[pos][i] + black_hash[pos][i];
  return return_value;
}

/* Returns an XOR of the two hash values. */
Hash_data
xor_hashvalues(Hash_data *hash1, Hash_data *hash2)
{
  int i;
  Hash_data return_value;

  for (i = 0; i < NUM_HASHVALUES; i++)
    return_value.hashval[i] = hash1->hashval[i] ^ hash2->hashval[i];
  return return_value;
}


#define BUFFER_SIZE (1 + NUM_HASHVALUES * (1 + (CHAR_BIT * SIZEOF_HASHVALUE \
						- 1) / 4))
char *
hashdata_to_string(Hash_data *hashdata)
{
  static char buffer[BUFFER_SIZE];
  int n = 0;
  int k;
  
  for (k = 0; k < NUM_HASHVALUES; k++) {
    n += sprintf(buffer + n, HASHVALUE_PRINT_FORMAT, hashdata->hashval[k]);
    gg_assert(n < BUFFER_SIZE);
  }

  return buffer;
}


/*
 * Local Variables:
 * tab-width: 8
 * c-basic-offset: 2
 * End:
 */
