/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:51:32 by shuwang           #+#    #+#             */
/*   Updated: 2024/08/05 20:56:32 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_spliter{
	int	spliter_0;
	int	spliter_1;
	int	spliter_2;
	int	spliter_3;
	int	spliter_4;
}	t_spliter;

typedef struct s_vars
{
	int		target_index;
	long	smallest_diff;
	int		find_target;
	int		b_value;
	int		a_size;
}	t_vars;

void	input_save_multiargv(int argc, char **argv, int **inputs, \
			int *num_elements);
char	**split_args_inquote(char **argv, int **inputs, int *count);
void	input_save_argvinquote(char **argv, int **inputs, int *num_elements);
void	copy_tab_tolst(t_list **lst, int *inputs, int num_elements);

int		all_digits(char *s);
int		check_double(int *num, int count);
int		int_overflow(const char *nptr, size_t i, int sign, long num);

void	sa(t_list **lsta, t_list **lstb);
void	sb(t_list **lsta, t_list **lstb);
void	ss(t_list **lsta, t_list **lstb);
void	pa(t_list **lst1, t_list **lst2);
void	pb(t_list **lst1, t_list **lst2);
void	ra(t_list **lsta, t_list **lstb);
void	rb(t_list **lsta, t_list **lstb);
void	rr(t_list **lsta, t_list **lstb);
void	rra(t_list **lsta, t_list **lstb);
void	rrb(t_list **lsta, t_list **lstb);
void	rrr(t_list **lsta, t_list **lstb);

int		lst_sorted(t_list *lst);
void	lst_sort(t_list **lsta, t_list **lstb, t_spliter *spl);
int		lst_value(t_list **lst);
int		lst_index_value(t_list *lst, int index);
void	lst_sort_small(t_list **lsta, t_list **lstb);
int		lst_max_index(t_list *lst);
int		lst_min_index(t_list *lst);

void	push_low_cost_btoa(t_list **lsta, t_list **lstb);
int		step_move_top(t_list *lst, int index);
void	push_move_tog(t_list **lsta, t_list **lstb, int *stepa, int *stepb);
void	push_move_sep(t_list **lsta, t_list **lstb, int *stepa, int *stepb);

int		ft_abs(int num);
int		in_range(int start, int end, t_list **lst);
void	ft_swap(int *a, int *b);

int		*inputs_dup(int *inputs, int num);
void	ft_b_sort(int *inputs, int num);
void	set_spliter(t_spliter *spl, int *inputs, int num, t_list *lst);

void	in_fail_multiargv(int **inputs);
void	in_fail_argvinquote(int **inputs, char **args_inquote);
void	ft_lstclear_nfunc(t_list **lst);
void	delete_stack(t_list **lsta, t_list **lstb, int	*inputs);
void	free_tab(char **tab);

#endif
