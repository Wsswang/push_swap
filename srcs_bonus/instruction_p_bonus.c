/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_p_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:38:20 by shuwang           #+#    #+#             */
/*   Updated: 2024/08/06 12:45:42 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	p(t_list **lst1, t_list **lst2)
{
	t_list	*temp;

	if (ft_lstsize(*lst1) == 0)
		return ;
	temp = *lst1;
	*lst1 = (*lst1)->next;
	ft_lstadd_front(lst2, temp);
}

void	pa_bonus(t_list **lsta, t_list **lstb)
{
	p(lstb, lsta);
}

void	pb_bonus(t_list **lsta, t_list **lstb)
{
	p(lsta, lstb);
}
