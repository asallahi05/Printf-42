/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asallahi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:54:50 by asallahi          #+#    #+#             */
/*   Updated: 2021/12/04 16:55:08 by asallahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print(char c, va_list pr, int *i)
{
	if (c == '%')
		(*i) += ft_putchar('%');
	else if (c == 'd' || c == 'i')
		(*i) += ft_putnbr(va_arg(pr, int));
	else if (c == 'c')
		(*i) += ft_putchar(va_arg(pr, int));
	else if (c == 's')
		(*i) += ft_putstr(va_arg(pr, char *));
	else if (c == 'x')
		(*i) += ft_hexa(va_arg(pr, unsigned int), 1);
	else if (c == 'X')
		(*i) += ft_hexa(va_arg(pr, unsigned int), 0);
	else if (c == 'p')
	{
		ft_putstr("0x");
		(*i) += 2;
		(*i) += ft_hexa(va_arg(pr, unsigned long), 1);
	}
	else if (c == 'u')
		(*i) += ft_unsigned_int(va_arg(pr, unsigned int));
	else
		(*i) += ft_putchar(c);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	pr;

	i = 0;
	va_start(pr, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (i);
			print(*format, pr, &i);
		}
		else
		{
			ft_putchar(*format);
			i++;
		}
		format++;
	}
	va_end(pr);
	return (i);
}
