Goal: examine the potential for recovering ephemeral keys/passphrases from
memory in a variety of different contexts.

# Example 1 - Using memory without sanitizing it afterwards

test1.c allocates a string buffer, fills it with a pre-determined string, and
then exits. The contents of this buffer should be easily recoverable.

TODO: test how this works with different amounts of memory available to the system.

TODO: might be interesting to see the behavior if a program exists (has automatic cleanup) vs. aborts.

Compile with:

	gcc -Wall test1.c util.c -o test1

I can't actually find the buffer in memory. I am using

	sudo strings /dev/mem | egrep 'A{8,}'

After some frustration, it appears the answer is changes to the kernel that have

1. disabled kmem
2. limited mem

for security reasons. Why this is not in the man page I do not know. It is discussed thoroughly here: https://bbs.archlinux.org/viewtopic.php?id=121964. 

	garrett@debian:~/ephemeral_keys$ grep -i devmem /boot/config-2.6.32-5-amd64 
	CONFIG_STRICT_DEVMEM=y

So the only solution is to... recompile the kernel.
