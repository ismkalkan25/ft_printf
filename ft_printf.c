#include "ft_printf.h"

static int	handle_format(const char *format, va_list args, int *count)
{
	int	ret;

	ret = 0;
	if (*format == 'c')
		ret = ft_putchar(va_arg(args, int), count);
	else if (*format == 's')
		ret = ft_putstr(va_arg(args, char *), count);
	else if (*format == 'p')
		ret = ft_putptr(va_arg(args, void *), count);
	else if (*format == 'd' || *format == 'i')
		ret = ft_putnbr(va_arg(args, int), count);
	else if (*format == 'u')
		ret = ft_putunsigned(va_arg(args, unsigned int), count);
	else if (*format == 'x')
		ret = ft_puthex(va_arg(args, unsigned int), 0, count);
	else if (*format == 'X')
		ret = ft_puthex(va_arg(args, unsigned int), 1, count);
	else if (*format == '%')
		ret = ft_putchar('%', count);
	else
		ret = ft_putchar(*format, count);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		ret;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
			{
				if (ft_putchar('%', &count) == -1)
					return (va_end(args), -1);
				break;
			}
			ret = handle_format(format, args, &count);
			if (ret == -1)
				return (va_end(args), -1);
			format++;
		}
		else
		{
			if (ft_putchar(*format, &count) == -1)
				return (va_end(args), -1);
			format++;
		}
	}
	va_end(args);
	return (count);
}
