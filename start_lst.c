/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:40:21 by mmanley           #+#    #+#             */
/*   Updated: 2018/04/23 11:58:31 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst		*lst_init(long nbr)
{
	t_lst	*new;

	if (nbr > MAX_INT || nbr < MIN_INT)
	{
		ft_printf("TOO BIG || SMALL : %ld\n", nbr);
		return (NULL);
	}
	if (!(new = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
		new->data = nbr;
	new->grp = -1;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

int			data_check(t_lst *lst, int curr)
{
	t_lst	*tmp;

	if (!lst)
		return (0);
	else
	{
		tmp = lst;
		while (tmp->next != lst)
		{
			if (curr == tmp->data)
			{
				ft_printf("Same nbr = %d\n", curr);
				return (-1);
			}
			tmp = tmp->next;
		}
		return (1);
	}
}

void		lst_circular(t_lst **lst, t_lst *new)
{
	t_lst *tmp;

	if (!lst)
		return ;
	else if (*lst && new)
	{
		tmp = *lst;
		while (tmp->next != *lst)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = *lst;
		(*lst)->prev = new;
		tmp->next = new;
	}
	else if (new)
	{
		if (!(*lst = (t_lst*)malloc(sizeof(t_lst))))
			return ;
		*lst = new;
		(*lst)->next = *lst;
		new->prev = *lst;
	}
}
