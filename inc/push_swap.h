/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:34:24 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/04/12 17:13:32 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/inc/libft.h" 

typedef struct s_stack_node
{
	long				nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

// handle errors
int						check_errors(int ac, char **av);
int						syntax_check(int ac, char **av);
int						limits_check(long *arr, int ac);
int						nb_repeats(long *arr, int ac);
int						already_sorted(long *arr, int ac);
int						check_errors_checker(int ac, char **av);

// stack initiation
void					printstack(t_stack_node **stack, char c);
t_stack_node			*new_node(long n);
void					lstadd_back(t_stack_node **stack, t_stack_node *new);
void					set_current_position(t_stack_node **stack);
void					stack_init(t_stack_node **stack, int ac, char **av);
int						get_median(t_stack_node **a, int len);
void					del_pointer(void *ptr);
void					free_stack(t_stack_node **stack, void (*del)(void*));

// nodes initiation
t_stack_node			*find_min(t_stack_node **a);
t_stack_node			*init_nodes(t_stack_node **a, t_stack_node **b);

// stack utils
//		errors utils
long					ft_atol(char *s);
void					list_array(long *arr, int ac, char **av);
int						check_and_free(long *arr, int error);
//		stack_init utils
void					bubble_sort(int arr[], int len);
int						get_median(t_stack_node **a, int len);
//		init_nodes utils
t_stack_node			*find_min(t_stack_node **a);
t_stack_node			*find_biggest(t_stack_node **stack);
void					cheapest_below_median(t_stack_node **a, int median);

// commands utils
t_stack_node			*ft_findlast(t_stack_node **stack);

// commands
void					pa(t_stack_node **a, t_stack_node **b, bool print);
void					pb(t_stack_node **a, t_stack_node **b, bool print);
void					ra(t_stack_node **a, bool print);
void					rb(t_stack_node **b, bool print);
void					rr(t_stack_node **a, t_stack_node **b, bool print);
void					rra(t_stack_node **a, bool print);
void					rrb(t_stack_node **b, bool print);
void					rrr(t_stack_node **a, t_stack_node **b, bool print);
void					sa(t_stack_node **a, bool print);
void					sb(t_stack_node **b, bool print);
void					ss(t_stack_node **a, t_stack_node **b, bool print);

// algorithms
void					sort_three(t_stack_node **a);
void					sort_stack(t_stack_node **a, t_stack_node **b);
long					stack_len(t_stack_node **stack);
void					mv_cheapest(t_stack_node **a, t_stack_node **b, \
						t_stack_node *cheapest);
void					top_min(t_stack_node **a);
void					push_leave_three(t_stack_node **a, t_stack_node **b);

#endif