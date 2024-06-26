/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:28:24 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/04/12 16:06:09 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rr(a, b, 1);
	if (*a != cheapest->target_node)
		while (*a != cheapest->target_node)
			ra(a, 1);
	else
		while (*b != cheapest)
			rb(b, 1);
}

void	rrotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rrr(a, b, 1);
	if (*a != cheapest->target_node)
		while (*a != cheapest->target_node)
			rra(a, 1);
	else
		while (*b != cheapest)
			rrb(b, 1);
}

void	oppos_rotate(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*a != cheapest->target_node)
	{
		if (cheapest->target_node->above_median)
			ra(a, 1);
		else
			rra(a, 1);
	}
	while (*b != cheapest)
	{
		if (cheapest->above_median)
			rb(b, 1);
		else
			rrb(b, 1);
	}
}

void	mv_cheapest(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(a, b, cheapest);
	else if (cheapest->above_median == 0
		&& cheapest->target_node->above_median == 0)
		rrotate_both(a, b, cheapest);
	else
		oppos_rotate(a, b, cheapest);
	pa(a, b, 1);
}

void	top_min(t_stack_node **a)
{
	t_stack_node	*min;

	min = find_min(a);
	while (*a != min)
	{
		if (min->above_median)
			ra(a, 1);
		else
			rra(a, 1);
	}
}
