#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void*
ec_malloc(size_t size) {
	/* malloc the given memory. abort if the malloc fails */
	void* ptr = malloc(size);
	if(ptr == NULL) {
		fputs("ERROR: could not allocate memory", stderr);
		exit(EXIT_FAILURE);
	}
	return ptr;
}

char*
allocate_example_buffer(int len) {
	assert(len > 1);
	char* buf = ec_malloc(len);
	/* Write len A's into the buffer */
	/* TODO would a pattern, like abcabca... be better? */
	int i;
	for(i=0; i<len-1; i++) {
		buf[i] = 'A';
	}
	buf[len-1] = '\0';
	return buf;
}
