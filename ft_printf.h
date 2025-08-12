/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eratasoy <eratasoy@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 19:48:54 by eratasoy          #+#    #+#             */
/*   Updated: 2025/08/12 19:48:58 by eratasoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define DECIMAL "0123456789"
# define HEX_DECIMAL "0123456789abcdef"
# define HEX_UP_DECIMAL "0123456789ABCDEF"

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_print_num(long long num, char type, char *base);
int	ft_putstr(char *s);
#endif
