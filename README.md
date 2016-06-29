# ptrace_study


=19:51:03=@~/tmp/ptrace
>> ps -aux | grep dummy2
zhalin    7444  0.5  0.2 391784 35540 pts/22   Tl   19:48   0:00
emacs -nw dummy2.c
zhalin    7468  0.0  0.0   4228   740 pts/20   T    19:49   0:00
./dummy2
zhalin    7518  0.0  0.0   4228   716 pts/20   S+   19:51   0:00
./dummy2
zhalin    7520  0.0  0.0  13696  2496 pts/22   S+   19:51   0:00
grep --color=auto dummy2
zhalin   25898  0.0  0.2 392424 34796 pts/5    Tl   09:36   0:00
emacs -nw dummy2.c
zhalin   27475  0.0  0.2 392420 34436 pts/5    Tl   10:43   0:00
emacs -nw dummy2.c

=19:51:15=@~/tmp/ptrace
>> sudo ./pokeuser 7518
tracee : 7518
status: 0

0000000000000000
0000000000000000
202570acff7f0000
e02270acff7f0000
ffffffff00000000
602270acff7f0000
4602000000000000
0800000000000000
0000000000000000
602370acff7f0000
fcfdffffffffffff
602e55242e7f0000
0000000000000000
502270acff7f0000
502270acff7f0000
2300000000000000
602e55242e7f0000
3300000000000000
4602000000000000
482270acff7f0000
2b00000000000000
0087a4242e7f0000
0000000000000000
0000000000000000
0000000000000000
0000000000000000
0000000000000000

rip:24552e60 code:̀�
The process stopped, putting back the original instructions 
Press <enter> to continue 

rip:24552e60 backup:H=


=19:50:01=@~/tmp/ptrace
>> ./dummy2 
My counter: 0
My counter: 1
My counter: 2
My counter: 3
My counter: 4
My counter: 5
My counter: 6
Segmentation fault (core dumped)

