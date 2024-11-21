/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:23:50 by akunegel          #+#    #+#             */
/*   Updated: 2023/09/21 14:23:51 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack(t_list **stack, int ac, char **av)
{
	t_list	*lst;
	int		i;
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
		lst = ft_lstnew(ft_atoi(arg[i]));
		ft_lstadd_back(stack, lst);
		i++;
	}
	ft_index(stack);
	if (ac == 2)
		ft_free(arg);
}

static void	sorter(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		polysort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (ac < 2)
		return (-1);
	parsing(ac, av);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	stack(stack_a, ac, av);
	if (sortor(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sorter(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
