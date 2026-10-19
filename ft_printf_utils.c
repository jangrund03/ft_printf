/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagrund <jagrund@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 17:14:47 by jagrund           #+#    #+#             */
/*   Updated: 2026/10/19 18:53:41 by jagrund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	char	c;
	int		count;

	count = 0;

	if (n >= 10)
		count += ft_putunsigned(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	count += 1;
	return (count);
}

int	ft_putuhexa(unsigned long n, char *base)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 16)
		count += ft_putuhexa(n / 16, base);
	c = base[n % 16];
	write(1, &c, 1);
	count += 1;
	return (count);
}
