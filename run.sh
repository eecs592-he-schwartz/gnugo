#!/usr/bin/bash
gnugo --mode gtp --boardsize 19 --quiet --komi 6.5 --score aftermath --capture-all-dead --chinese-rules --simple-ko --forbid-suicide --cache-size 256 --resign-allowed
