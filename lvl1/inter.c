#include <unistd.h>

int	instr(char ch, char *str, int len)
{
	int	i = 0;

	while (str[i] && (i < len || len == -1))
		if (str[i++] == ch)
			return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i = -1;

	if (argc == 3)
		while (argv[1][++i])	
			if (!instr(argv[1][i], argv[1], i) && instr(argv[1][i], argv[2], -1))
				write(1, &argv[1][i], 1);
	write(1, "\n", 1);
	return (0);
}
