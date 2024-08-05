/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:55:16 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/02 16:55:26 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **tab)
{
	int	i;
	i = 0;

	if (tab == NULL)
		return ;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

int     in_range(int start, int end, t_list **lst)
{
    if (lst_value(lst) >= start && lst_value(lst) < end)
        return (1);
    return (0);
}

/* void	lst_print(t_list *lst)
{
	int	*value;

	while(lst)
	{
		value = (int *)(lst->content);
		ft_printf("%d ", *value);
		lst = lst->next;
	}
	ft_printf("\n");
} */

/* void	print_stack(t_list *lsta, t_list *lstb)
{
	ft_printf("stack a: ");
	lst_print(lsta);
	ft_printf("stack b: ");
	lst_print(lstb);
} */

int     ft_abs(int num)
{
    if (num < 0)
        return (-num);
    else
        return (num);
}

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}