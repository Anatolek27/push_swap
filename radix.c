/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:22:53 by akunegel          #+#    #+#             */
/*   Updated: 2023/09/21 14:22:55 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bit_max(t_list **stack)
{
	t_list	*lst;
	int		max;
	int		max_bit;

	lst = *stack;
	max = lst->i;
	max_bit = 0;
	while (lst)
	{
		if (lst->i > max)
			max = lst->i;
		lst = lst->next;
	}
	while ((max >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

void	radix_sort(t_list **stacka, t_list **stackb)
{
	t_list	*lst;
	int		i;
	int		j;
	int		l;
	int		max_bit;

	i = 0;
	lst = *stacka;
	l = ft_lstsize(lst);
	max_bit = bit_max(stacka);
	while (i < max_bit)
	{
		j = 0;
		while (j++ < l)
		{
			lst = *stacka;
			if (((lst->i >> i) & 1) == 1)
				ra(stacka);
			else
				pb(stacka, stackb);
		}
		while (ft_lstsize(*stackb) != 0)
			pa(stacka, stackb);
		i++;
	}
}
