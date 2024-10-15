/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:15:12 by fzayani           #+#    #+#             */
/*   Updated: 2024/08/06 15:47:30 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int		g_client_pid = 0;

void	ft_btoa(int sign, siginfo_t *info, void *context)
{
	static int	bits;
	static int	i;

	(void)context;
	if (info->si_pid)
		g_client_pid = info->si_pid;
	if (sign == SIGUSR1)
		i += (0x01 << bits);
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", i);
		bits = 0;
		i = 0;
	}
	if (g_client_pid != 0)
	{
		kill(g_client_pid, SIGUSR1);
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					pid;

	(void)av;
	if (ac != 1)
	{
		ft_printf("error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("PID = %d\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_btoa;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (ft_printf("error: failed to set SIGUSR1 handler\n"), 1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_printf("error: failed to set SIGUSR2 handler\n"), 1);
	while (1)
		pause();
	return (0);
}
