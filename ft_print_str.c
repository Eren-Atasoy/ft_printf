#include "ft_printf.h"
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	size_t	i;

	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return ((int)i);
}
