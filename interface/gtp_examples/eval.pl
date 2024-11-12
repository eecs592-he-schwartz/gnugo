#!/usr/bin/env perl
use v5.32;
use utf8;
use strict;
use warnings;
use File::Spec;
use Parallel::Loops;
use List::Util qw(shuffle);

# list of engines
my %engine2cmd = (
    fuego => '/eecs592/fuego/run.sh',
    gnugo => '/eecs592/gnugo/run.sh',
    katago => 'TODO',
);
my @engines = qw(fuego gnugo);
my $engineVengine = './2ptkgo.pl';
my $output_dir = $ARGV[0] // die "usage: $0 output_dir";

# get every pair of engines, order matters, including self-self
my $cartesian_product = sub{
    my @acc;
    for my $i (1..@_){
        for my $j (1..@_){
            push @acc, $_[$i - 1], $_[$j - 1];
        }
    }
    return @acc;
};

my @pairs = &$cartesian_product(@engines);
my @jobs;
my $i = 0;
while(@pairs){
    my $black = shift @pairs;
    my $white = shift @pairs;
    for(1..100){
        push @jobs, [$engineVengine, $engine2cmd{$black}, $engine2cmd{$white}, File::Spec->catfile($output_dir, "$black-$white-$i")];
        $i = $i + 1;
    }
}
@jobs = shuffle @jobs; # randomize job order to even out load

my $parallel = Parallel::Loops->new(6);
$parallel->foreach(\@jobs, sub {
        my $job = $_;
        system(@$job);
    });
