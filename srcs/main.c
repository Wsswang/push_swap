/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuwang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:56:55 by shuwang           #+#    #+#             */
/*   Updated: 2024/07/02 16:57:04 by shuwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*save_inputs(int *inputs, int argc, char **argv, int i)
{
	inputs = malloc(sizeof(int) * (argc - 1));
	if (inputs == NULL)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	while(i < argc)
	{
		if (all_digits(argv[i]) && !int_overflow(argv[i]))
			inputs[i - 1] = ft_atoi(argv[i]);
		else
		{
			write(2, "Error\n", 6);
			free(inputs);
			return (NULL);
		}
		i++;
	}
	if (check_double(inputs, i - 1))
	{
		write(2, "Error\n", 6);
		free(inputs);
		return (NULL);
	}
	return (inputs);
}

void	input_save_multiargv(int argc, char **argv, int **inputs, int *num_elements)
{
	int	i;

	*num_elements = argc - 1;
	*inputs = malloc(sizeof(int) * (argc - 1));
	if (*inputs == NULL)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	i = 1;
	while(i < argc)
	{
		if (all_digits(argv[i]) && !int_overflow(argv[i]))
			(*inputs)[i - 1] = ft_atoi(argv[i]);
		else
		{
			write(2, "Error\n", 6);
			free(*inputs);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (check_double(*inputs, i - 1))
	{
		write(2, "Error\n", 6);
		free(*inputs);
		exit(EXIT_FAILURE);
	}
}

void	input_save_argvinquote(char **argv, int **inputs, int *num_elements)
{
		char **args_inquote;
		int	j = 0;
		int count = 0;

		args_inquote = ft_split(argv[1], ' ');
		if (args_inquote == NULL)
			exit(EXIT_FAILURE);
		else
		{
			while (args_inquote[count])
				count++;
			*inputs = malloc(sizeof(int) * (count));
			if (!inputs)
			{
				free_tab(args_inquote);
				exit(EXIT_FAILURE);
			}
		}
		while (args_inquote[j])
		{
			if (all_digits(args_inquote[j]) && !int_overflow(args_inquote[j]))
			{
				(*inputs)[j] = ft_atoi(args_inquote[j]);
				j++;
			}
			else
			{
				write(2, "Error\n", 6);
				free_tab(args_inquote);
				free(*inputs);
				exit(EXIT_FAILURE);
			}
		}
		if (check_double(*inputs, count))
		{
			write(2, "Error\n", 6);
			free_tab(args_inquote);
			free(*inputs);
			exit(EXIT_FAILURE);
		}
		free_tab(args_inquote);
		*num_elements = count;
}

void	copy_tab_tolst(t_list **lst, int *inputs, int num_elements)////maybe use int to return a value
{
	int	i;
	i = 0;
	while (i < num_elements)
	{
		ft_lstadd_back(lst, ft_lstnew((void *) (&inputs[i])));  //此处如果lstnew fail 有可能leak protect!!!!!!!!!!!!!
		i++;
	}
}

/* void	push_swap(t_list *lsta, t_list *lstb, t_spliter *spl)
{
	if (lst_sorted(lsta))
		return ;
	lst_sort(&lsta, &lstb, spl);
} */

int	*inputs_dup(int *inputs, int num)
{
	int	i;
	int *inputs_copy;

	i = 0;
	inputs_copy = malloc(sizeof(int) * num);
	if (inputs_copy == NULL)
	{
		free(inputs);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	while (i < num)
	{
		inputs_copy[i] = inputs[i];
		i++;
	}
	return (inputs_copy);
}

void	ft_b_sort(int *inputs, int num)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < num)
	{
		j = 0;
		while (j < num)
		{
			if (inputs[i] < inputs[j] && i != j)
				ft_swap(&inputs[i], &inputs[j]);
			j++;
		}
		i++;
	}
}

/* void	ft_print_array(int *inputs, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		ft_printf("%d\n", inputs[i]);
		i++;
	}
} */

void	set_spliter(t_spliter *spl, int *inputs, int num)
{
	spl->spliter_0 = inputs[0];
	spl->spliter_1 = inputs[num / 4];
	spl->spliter_2 = inputs[num / 4 * 2];
	spl->spliter_3 = inputs[num / 4 * 3];
	spl->spliter_4 = inputs[num -1];
	free(inputs);
}	

int	main(int argc, char **argv)
{
	int	*inputs;
	int	*inputs_copy;
	t_list	*lsta;
	t_list	*lstb;
	int num_elements;
	t_spliter spl;

	inputs = NULL;
	lsta = NULL;
	lstb = NULL;
	num_elements = 0;
	if (argc == 2)
		input_save_argvinquote(argv, &inputs, &num_elements);
	else
		input_save_multiargv(argc, argv, &inputs, &num_elements);
	copy_tab_tolst(&lsta, inputs, num_elements);
	inputs_copy = inputs_dup(inputs, num_elements);
	ft_b_sort(inputs_copy, num_elements);
	set_spliter(&spl, inputs_copy, num_elements);
	lst_sort(&lsta, &lstb, &spl);
	ft_lstclear_nfunc(&lsta);
	free(inputs);
	return (0);
}
