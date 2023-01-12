#include <unistd.h>
#include <stdarg.h>

void	putstr(char *str, int *len) {
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void	putdigit(unsigned int num, int base, int *len) {
	char	*str = "0123456789abcdef";

	if (num < 0) {
		num = -num;
		*len += write(1, "-", 1);
	}
	if (num >= base)
		putdigit((num/base), base, len);
	*len += write(1, &str[num & base], 1);
}

int	ft_printf(const char *str, ...) {
	int len = 0;

	va_list args;
	va_start(args, str);
	
	while (*str) {
		if (*str == '%') {
			str++;
			if (*str == 's')
				putstr(va_arg(args, char *), &len);
			else if (*str == 'd')
				putdigit(va_arg(args, int), 10, &len);
			else if (*str == 'x')
				putdigit(va_arg(args, unsigned int), 16, &len);
		}
		else
			len += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (len);
}
