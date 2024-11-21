/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:23:54 by akunegel          #+#    #+#             */
/*   Updated: 2023/09/21 14:23:56 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_list	*next_min(t_list **stack)
{
	t_list	*lst;
	t_list	*min;
	int		mini;

	min = NULL;
	mini = 0;
	lst = *stack;
	if (lst)
	{
		while (lst)
		{
			if ((lst->i == -1) && (!mini || lst->val < min->val))
			{
				min = lst;
				mini = 1;
			}
			lst = lst->next;
		}
	}
	return (min);
}

int	geti(t_list **stack, int i)
{
	t_list	*lst;
	int		j;

	j = 0;
	lst = *stack;
	while (lst)
	{
		if (lst->i == i)
			break ;
		j++;
		lst = lst->next;
	}
	return (j);
}

void	ft_index(t_list **stack)
{
	t_list	*lst;
	int		i;

	i = 0;
	lst = next_min(stack);
	while (lst)
	{
		lst->i = i;
		lst = next_min(stack);
		i++;
	}
}
