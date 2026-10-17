/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagrund <jagrund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 18:25:31 by jagrund           #+#    #+#             */
/*   Updated: 2026/10/17 20:15:41 by jagrund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}


int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long	nb;
	char	c;
	int		count;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		count += 1;
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
	count += 1;
	return (count);
}

static int	ft_handle_format(const char *format, va_list args, int *i)
{
	if (!format[*i])
		return (0);
	if (format[*i] == 'd' || format[*i] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (format[*i] == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (format[*i] == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (format[*i] == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i += 1;
			count += ft_handle_format(format, args, &i);
			i += 1;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	int	r;
	r = ft_printf("%i a %d\n", 42, 42);
	ft_printf("%d\n", r);
}
