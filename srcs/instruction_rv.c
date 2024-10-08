/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:38:51 by shuwang           #+#    #+#             */
/*   Updated: 2024/08/05 19:22:52 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rv(t_list **lst)
{
	t_list	*last;
	t_list	*beforelast;
	t_list	*curr;

	if (ft_lstsize(*lst) <= 1)
		return ;
	curr = *lst;
	while (curr->next->next != NULL)
		curr = curr->next;
	beforelast = curr;
	last = curr->next;
	beforelast->next = NULL;
	last->next = *lst;
	*lst = last;
}

void	rra(t_list **lsta, t_list **lstb)
{
	(void)lstb;
	rv(lsta);
	ft_printf("rra\n");
}

void	rrb(t_list **lsta, t_list **lstb)
{
	(void)lsta;
	rv(lstb);
	ft_printf("rrb\n");
}

void	rrr(t_list **lsta, t_list **lstb)
{
	rv(lsta);
	rv(lstb);
	ft_printf("rrr\n");
}
