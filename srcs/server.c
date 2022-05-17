/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:34:50 by ekern             #+#    #+#             */
/*   Updated: 2022/05/17 18:01:14 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	fc_test(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("0");
	else if (sig == SIGUSR2)
		ft_printf("1");
}

int	main(void)
{
	ft_printf("PID : %d\n", getpid());
	signal(SIGUSR1, fc_test);
	signal(SIGUSR2, fc_test);
	while (1)
		pause();
	return (0);
}