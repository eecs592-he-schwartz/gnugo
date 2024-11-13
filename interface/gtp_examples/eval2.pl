#!/usr/bin/env perl
use v5.32;
use utf8;
use strict;
use warnings;
use File::Spec;
use List::Util qw(shuffle);
use IPC::SysV qw(IPC_PRIVATE S_IRUSR S_IWUSR IPC_CREAT S_IRWXU);
use IPC::SharedMem;
use IPC::Semaphore;

# list of engines
my %engine2cmd = (
    fuego => '/eecs592/fuego/run.sh',
    gnugo => '/eecs592/gnugo/run.sh',
    #katago => 'TODO',
);
my %engine2resources = (
    # engine => memory (GB), cpu (threads)
    fuego => [16, 8],
    gnugo => [1, 1],
    #katago => 'TODO',
);
my @engines = qw(fuego gnugo);
my $engineVengine = './2ptkgo.pl';
my $output_dir = $ARGV[0] // die "usage: $0 output_dir";
sub free{
    $_ = `free -g | sed -n '2p' | awk '{print \$4}'`;
    chomp;
    return $_;
};
my $num_threads_using;
my $shm = IPC::SharedMem->new(IPC_PRIVATE, 8, S_IRWXU);
$shm->write(pack('q', 0), 0, 8);
$num_threads_using = $shm->read(0, 8);
$num_threads_using = unpack('q', $num_threads_using);
my $sem = IPC::Semaphore->new(IPC_PRIVATE, 1, S_IRUSR | S_IWUSR | IPC_CREAT);
$sem->op(0, 1, 0);

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
        push @jobs, [$black, $white, File::Spec->catfile($output_dir, "$black-$white-$i")];
        $i = $i + 1;
    }
}
@jobs = shuffle @jobs; # randomize job order to even out load

while(@jobs){
    my $job = shift @jobs;
    my ($black_mem, $black_cpu) = @{$engine2resources{$job->[0]}};
    my ($white_mem, $white_cpu) = @{$engine2resources{$job->[1]}};
    #say free();
    #say $black_mem + $white_mem;
    #say $num_threads_using + $black_cpu + $white_cpu;
    while(free() < ($black_mem + $white_mem) || ($num_threads_using + $black_cpu + $white_cpu) > 64){
        sleep(10); # busy wait
    }
    $sem->op(0, -1, 0);
    $num_threads_using = $shm->read(0, 8);
    $num_threads_using = unpack('q', $num_threads_using);
    $num_threads_using = $num_threads_using + $black_cpu + $white_cpu;
    $shm->write(pack('q', $num_threads_using), 0, 8);
    $sem->op(0, 1, 0);
    my $pid = fork() // die "fork failed: $!";
    if($pid){
        system($engineVengine, $engine2cmd{$job->[0]}, $engine2cmd{$job->[1]}, $job->[2]);
        $sem->op(0, -1, 0);
        $num_threads_using = $shm->read(0, 8);
        $num_threads_using = unpack('q', $num_threads_using);
        $num_threads_using = $num_threads_using - $black_cpu - $white_cpu;
        $shm->write(pack('q', $num_threads_using), 0, 8);
        $sem->op(0, 1, 0);
        exit 0;
    }
}
