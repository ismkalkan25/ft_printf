#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c, int *count);
int	ft_putstr(char *s, int *count);
int	ft_putnbr(long n, int *count);
int	ft_puthex(unsigned long n, int upper, int *count);
int	ft_putptr(void *ptr, int *count);
int	ft_putunsigned(unsigned int n, int *count);

#endif