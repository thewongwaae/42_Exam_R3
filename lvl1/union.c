#include <unistd.h>

int instr(char ch, const char *str, int len) {
	int i = 0;

	if (len == -1) {
		while (str[i])
			if (str[i++] == ch)
				return (1);
	} else {
		while (i < len)
			if (str[i++] == ch)
				return (1);
	}
	return (0);
}

int main(int argc, char **argv) {
	int i = -1;
	int j = -1;

	if (argc == 3) {
		while (argv[1][++i])
			if (!instr(argv[1][i], argv[1], i))
				write(1, &argv[1][i], 1);
		while (argv[2][++j])
			if (!instr(argv[2][j], argv[1], -1) && !instr(argv[2][j], argv[2], j))
				write(1, &argv[2][j], 1);
	}
	write(1, "\n", 1);
	return (0);
}
