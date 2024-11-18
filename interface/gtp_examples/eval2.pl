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
# since we're typically running these overnight/for long durations, want to run
# 2ptkgo.pl headlessly. But 2ptkgo.pl relies on the perl/Tk main event loop
# (waiting for engine output events), so let's just use xvfb to fake a display
my @engineVengine = qw(xvfb-run -a ./2ptkgo.pl);
my $output_dir = $ARGV[0] // die "usage: $0 output_dir";
sub free{
    $_ = `free -g | sed -n '2p' | awk '{print \$4}'`;
    chomp;
    return $_;
};
my $shm = IPC::SharedMem->new(IPC_PRIVATE, 8, S_IRWXU);
$shm->write(pack('q', 0), 0, 8);
my $sem = IPC::Semaphore->new(IPC_PRIVATE, 1, S_IRUSR | S_IWUSR | IPC_CREAT);
$sem->setval(0, 1); # initialize the lock to free
sub get_num_threads_using{
    my $num_threads_using = $shm->read(0, 8);
    $num_threads_using = unpack('q', $num_threads_using);
    return $num_threads_using;
};
sub set_num_threads_using{
    $shm->write(pack('q', $_[0]), 0, 8);
};

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
    #say $num_threads_using;
    #say $black_cpu + $white_cpu;
    $sem->op(0, -1, 0);
    my $num_threads_using = get_num_threads_using();
    $sem->op(0, 1, 0);
    if(free() < ($black_mem + $white_mem) ||
        ($num_threads_using + ($black_cpu + $white_cpu)) > 64){
        push @jobs, $job;
        sleep(2); # busy wait
        next;
    }
    $sem->op(0, -1, 0);
    set_num_threads_using(get_num_threads_using() + ($black_cpu + $white_cpu));
    $sem->op(0, 1, 0);
    if((fork() // die "fork failed: $!") == 0){
        #open(STDOUT, '>', '/dev/null');
        #open(STDERR, '>', '/dev/null');
        system(@engineVengine, $engine2cmd{$job->[0]}, $engine2cmd{$job->[1]}, $job->[2]);
        $sem->op(0, -1, 0);
        set_num_threads_using(get_num_threads_using() - ($black_cpu + $white_cpu));
        $sem->op(0, 1, 0);
        exit 0;
    }
}
