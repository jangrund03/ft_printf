/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagrund <jagrund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 18:25:31 by jagrund           #+#    #+#             */
/*   Updated: 2026/10/15 20:58:01 by jagrund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
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
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
	count += 1;
}

static void	ft_handle_format(const char *format, va_list args, int *i)
{
	if (format[*i] == 'd')
		ft_putnbr(va_arg(args, int));
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
		if (format[i] == '%' && format[i + 1] == 'd')
		{
			i += 1;
			ft_handle_format(format, args, &i);
			i += 1;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
		}
	}
	va_end(args);
	return (i);
}

int	main(void)
{
	ft_printf("Ahoj %d konec\n", 123);
	return (0);
}
