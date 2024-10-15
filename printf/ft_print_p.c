/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:12:33 by fzayani           #+#    #+#             */
/*   Updated: 2024/05/30 13:22:44 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(unsigned long address)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (!address)
		return (ft_putstr("(nil)"));
	if (address >= 16)
		i += ft_print_p(address / 16);
	i += ft_putchar(base[address % 16]);
	return (i);
}
