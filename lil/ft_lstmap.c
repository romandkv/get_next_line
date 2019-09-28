/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:00:04 by pshock            #+#    #+#             */
/*   Updated: 2019/09/15 19:27:28 by pshock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *new_list;
	t_list *buf;

	if (!f || !lst)
		return (NULL);
	buf = (*f)(lst);
	if (!(new_list = ft_lstnew(buf->content, buf->content_size)))
		return (NULL);
	head = new_list;
	lst = lst->next;
	while (lst)
	{
		if (!(buf = (*f)(lst)))
			return (NULL);
		if (!(new_list->next = ft_lstnew(buf->content, buf->content_size)))
			return (NULL);
		new_list = new_list->next;
		lst = lst->next;
	}
	return (head);
}
