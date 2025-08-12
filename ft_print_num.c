/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <eratasoy@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 19:49:21 by eratasoy          #+#    #+#             */
/*   Updated: 2025/08/12 19:49:23 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	ft_get_len_base_unsigned(unsigned long long nbr, int base_len)
{
	int	length;

	length = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= base_len;
		length++;
	}
	return (length);
}

static void	ft_put_nbr(int n, char *base)
{
	int	base_len;

	base_len = (int)ft_strlen(base);
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= base_len)
		ft_put_nbr(n / base_len, base);
	ft_putchar(base[n % base_len]);
}

static void	ft_put_unsigned_nbr(unsigned long long n, char *base)
{
	unsigned long long	base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
		ft_put_unsigned_nbr(n / base_len, base);
	ft_putchar(base[n % base_len]);
}

int	ft_print_num(long long num, char type, char *base)
{
	int					base_len;
	int					len;
	unsigned long long	abs_val;

	len = 0;
	base_len = (int)ft_strlen(base);
	if (type == 'd' || type == 'i')
	{
		ft_put_nbr((int)num, base);
		if (num < 0)
		{
			len++;
			abs_val = (unsigned long long)(-num);
		}
		else
			abs_val = (unsigned long long)num;
		return (len + ft_get_len_base_unsigned(abs_val, base_len));
	}
	else if (type == 'u' || type == 'x' || type == 'X')
	{
		ft_put_unsigned_nbr((unsigned long long)num, base);
		return (ft_get_len_base_unsigned((unsigned long long) num, base_len));
	}
	return (0);
}
