/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:00:53 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/04/12 20:07:14 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	if (ac >= 2)
		return (check_errors(ac, av), 0);
	stack_init(&a, ac, av);
	sort_stack(&a, &b);
	free_stack(&b, del_pointer);
	free_stack(&a, del_pointer);
	return (0);
}
