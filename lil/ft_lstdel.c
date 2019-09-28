/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:28:58 by pshock            #+#    #+#             */
/*   Updated: 2019/09/15 18:48:43 by pshock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *buf;

	if (!alst || !*alst || !del)
		return ;
	list = *alst;
	while (list)
	{
		(*del)((list)->content, (list)->content_size);
		buf = list->next;
		free(list);
		list = buf;
	}
	*alst = NULL;
}
