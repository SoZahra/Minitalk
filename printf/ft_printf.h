/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:34:22 by fzayani           #+#    #+#             */
/*   Updated: 2024/05/30 14:48:51 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putchar(char c);

int	ft_putstr(const char *str);

int	ft_printf(const char *format, ...);

int	ft_putnbr(long nb);

int	ft_putnbr_base(long int nbr, char *base);

int	ft_print_p(unsigned long address);

#endif