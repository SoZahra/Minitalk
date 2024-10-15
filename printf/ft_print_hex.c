/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:09:50 by fzayani           #+#    #+#             */
/*   Updated: 2024/05/30 14:47:22 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_rev(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		ft_putchar(str[i]);
		i--;
	}
}

int	ft_putnbr_base(long int nbr, char *base)
{
	int	len;
	int	base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		len += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= base_len)
		len += ft_putnbr_base(nbr / base_len, base);
	len += ft_putchar(base[nbr % base_len]);
	return (len);
}
