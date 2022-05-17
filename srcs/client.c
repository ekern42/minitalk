/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:34:45 by ekern             #+#    #+#             */
/*   Updated: 2022/05/17 18:01:28 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	fc_convert(char *str, char *pib)
{
	int	decimal;
	int	*binary;
	int	a;
	int	b;

	a = 24;
	decimal = str[0];
//	ft_printf("%d, ", decimal);
	binary = fc_dec_to_binary(decimal);
	 while(a <= 31)
	 	ft_printf("%d", binary[a++]);
		ft_putendl_fd("", 1);
	a = 24;
	while (a <= 31)
	{
		b = binary[a];
		ft_printf("%d", binary[a]);
		if (b == 0)
			kill(ft_atoi(pib), SIGUSR1);
		else
			kill(ft_atoi(pib), SIGUSR2);
		a++;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	if (ac != 3 || av[2] == NULL)
		return (1);
	ft_printf("Up : %d\n", ft_strlen(av[2]));
	fc_convert(av[2], av[1]);
	// if (av[2][0] == 48)
	// 	kill(ft_atoi(av[1]), SIGUSR1);
	// else if (av[2][0] == 49)
	// 	kill(ft_atoi(av[1]), SIGUSR2);
	// else if (av[2][0] == 'k')
	// 	kill(ft_atoi(av[1]), SIGKILL);
	return (0);
}
