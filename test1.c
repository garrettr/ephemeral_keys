#include <stdio.h>
#include <stdlib.h>

#include "util.h"

#define BUFFER_LENGTH 64

int
main(int argc, char** argv) {
	// Allocate the example buffer and exit.
	char* buf = allocate_example_buffer(BUFFER_LENGTH);
	// Memory is freed by the kernel during exit.
	exit(EXIT_SUCCESS);
}
