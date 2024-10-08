/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort_small.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:00:07 by shuwang           #+#    #+#             */
/*   Updated: 2024/08/05 20:35:20 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_index_cmp(t_list *lst, int indexa, int indexb)
{
	int	size;

	size = ft_lstsize(lst);
	if (size > 3)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	if (lst_index_value(lst, indexa) > lst_index_value(lst, indexb))
		return (1);
	else
		return (0);
}

void	lst_sort_two(t_list **lsta, t_list **lstb)
{
	if (lst_index_cmp(*lsta, 0, 1))
		sa(lsta, lstb);
}

void	lst_sort_three(t_list **lsta, t_list **lstb)
{
	if (lst_index_cmp(*lsta, 0, 1) == 0 && lst_index_cmp(*lsta, 1, 2) == 0)
		;
	else if (lst_index_cmp(*lsta, 0, 1) == 0 && lst_index_cmp(*lsta, 1, 2) == 1 \
			&& lst_index_cmp(*lsta, 2, 0) == 1)
	{
		sa(lsta, lstb);
		ra(lsta, lstb);
	}
	else if (lst_index_cmp(*lsta, 0, 1) == 1 && lst_index_cmp(*lsta, 1, 2) == 0 \
			&& lst_index_cmp(*lsta, 2, 0) == 1)
		sa(lsta, lstb);
	else if (lst_index_cmp(*lsta, 0, 1) == 0 && lst_index_cmp(*lsta, 1, 2) == 1 \
			&& lst_index_cmp(*lsta, 2, 0) == 0)
		rra(lsta, lstb);
	else if (lst_index_cmp(*lsta, 0, 1) == 1 && lst_index_cmp(*lsta, 1, 2) == 0 \
			&& lst_index_cmp(*lsta, 2, 0) == 0)
		ra(lsta, lstb);
	else if (lst_index_cmp(*lsta, 0, 1) == 1 && lst_index_cmp(*lsta, 1, 2) == 1)
	{
		sa(lsta, lstb);
		rra(lsta, lstb);
	}
}

void	lst_sort_small(t_list **lsta, t_list **lstb)
{
	int	size;

	size = ft_lstsize(*lsta);
	if (size < 2)
		;
	else if (size == 2)
		lst_sort_two(lsta, lstb);
	else if (size == 3)
		lst_sort_three(lsta, lstb);
}
