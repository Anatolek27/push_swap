/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:19:49 by akunegel          #+#    #+#             */
/*   Updated: 2023/09/21 14:19:51 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_dooble(int n, int i, char **av)
{
	i++;
	while (av[i])
	{
		if (ft_atoi(av[i]) == n)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	parsing(int ac, char **av)
{
	int		i;
	long	tmp;
	char	**arg;

	i = 0;
	if (ac == 2)
		arg = ft_split(av[1], ' ');
	else
	{
		i = 1;
		arg = av;
	}
	while (arg[i])
	{
		tmp = ft_atoi(arg[i]);
		if (!ft_isnum(arg[i]))
			ft_error("error");
		if (ft_dooble(tmp, i, arg))
			ft_error("error");
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error("error");
		i++;
	}
	if (ac == 2)
		ft_free(arg);
}
