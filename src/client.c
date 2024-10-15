/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:13:23 by fzayani           #+#    #+#             */
/*   Updated: 2024/08/06 15:47:34 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int			g_is_response_received = 0;

static int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

void	ft_atob(int pid, char c)
{
	int	bits;
	int	i;

	bits = 0;
	while (bits < 8)
	{
		i = 0;
		if ((c & (0x01 << bits)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_is_response_received && i < 100)
		{
			usleep(10);
			i++;
		}
		if (i == 100)
		{
			ft_printf("Error\n");
			exit(1);
		}
		g_is_response_received = 0;
		bits++;
	}
}

void	sig_handler(int signum)
{
	(void)signum;
	g_is_response_received = 1;
	return ;
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
			return (ft_printf("error\n"));
		signal(SIGUSR1, sig_handler);
		while (av[2][i])
		{
			ft_atob(pid, av[2][i]);
			i++;
		}
	}
	else
	{
		ft_printf("error\n");
		return (1);
	}
	return (0);
}
