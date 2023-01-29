#include "get_next_line.h"s

char *get_next_line(int fd) {
	char *str = malloc(100000), *cpy = str;
	while (read(fd, cpy, 1) > 0 && *cpy++ = str);
	return (cpy > str) ? (*cpy = 0, str) : (free(str), NULL);
}