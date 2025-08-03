#include "ft_printf.h"

static int	ft_print_pointer(void *ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	count += ft_print_num((unsigned long long)ptr, 'x', HEX_DECIMAL);
	return (count);
}

static int	ft_print_by_type(char type, va_list *args)
{
	if (type == 'd' || type == 'i')
		return (ft_print_num(va_arg(*args, int), 'i', DECIMAL));
	if (type == 'u')
		return (ft_print_num(va_arg(*args, unsigned int), 'u', DECIMAL));
	if (type == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (type == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (type == '%')
		return (ft_putchar('%'));
	if (type == 'x')
		return (ft_print_num(va_arg(*args, unsigned int), 'x', HEX_DECIMAL));
	if (type == 'X')
		return (ft_print_num(va_arg(*args, unsigned int), 'X', HEX_UP_DECIMAL));
	if (type == 'p')
		return (ft_print_pointer(va_arg(*args, void *)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total_length;

	va_start(args, format);
	i = 0;
	total_length = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			total_length += ft_print_by_type(format[i], &args);
		}
		else
		{
			total_length += ft_putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (total_length);
}
