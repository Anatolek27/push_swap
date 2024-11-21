/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:23:00 by akunegel          #+#    #+#             */
/*   Updated: 2023/09/21 14:23:13 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*headto;
	t_list	*headfrom;
	t_list	*tmp;

	if (ft_lstsize(*stack_from) == 0)
		return (-1);
	headto = *stack_to;
	headfrom = *stack_from;
	tmp = headfrom;
	headfrom = headfrom->next;
	*stack_from = headfrom;
	if (!headto)
	{
		headto = tmp;
		headto->next = NULL;
		*stack_to = headto;
	}
	else
	{
		tmp->next = headto;
		*stack_to = tmp;
	}
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
