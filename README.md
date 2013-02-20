Goal: examine the potential for recovering ephemeral keys/passphrases from
memory in a variety of different contexts.

# Example 1 - Using memory without sanitizing it afterwards

test1.c allocates a string buffer, fills it with a pre-determined string, and
then exits. The contents of this buffer should be easily recoverable.

TODO: test how this works with different amounts of memory available to the system.
