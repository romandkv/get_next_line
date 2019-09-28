/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:50:03 by pshock            #+#    #+#             */
/*   Updated: 2019/09/17 13:07:09 by pshock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*res;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str) - 1;
	if (!(res = (char*)malloc(len + 2)) || len + 2 == 0)
		return (NULL);
	while (len > -1)
	{
		res[i] = str[len];
		i++;
		len--;
	}
	res[i] = '\0';
	return (res);
}
