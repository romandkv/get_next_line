/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:56:52 by pshock            #+#    #+#             */
/*   Updated: 2019/09/28 17:03:26 by pshock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*str2;

	i = 0;
	len = ft_strlen(str);
	if (!(str2 = (char*)malloc(len + 1)) || len + 1 == 0)
	{
		return (NULL);
	}
	while (i < len + 1)
	{
		str2[i] = str[i];
		i++;
	}
	return (str2);
}
