### getProcStartTime utility for AIX
https://stackoverflow.com/a/23815755/1680777

How to compile this program:

```
gcc getProcStartTime.c -o getProcStartTime
```
Here's the magic logic: AIX just like Linux has a process called init with PID 1. It can't be killed or restarted. So the start time of PID 1 is the boot time of your server.
```
./getProcStartTime 1
```
On my server, it returns `Wed Apr 23 10:33:30 2014`; yours will be different.

Note, I originally made getProcStartTime specifically for this purpose, but now I use it in all kinds of other scripts. Want to know how long an Oracle database has been up? Find the PID of Oracle's PMON and pass that PID as your arg after getProcStartTime.

If you really want the output as an integer number of seconds, it would be an easy programming exercise to modify the code above. The name getProcUptime is just a suggestion. Then you could just call:

```
./getProcUptime 1
```
