/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 20:37:37 by pshock            #+#    #+#             */
/*   Updated: 2019/09/15 16:04:52 by pshock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s1;
	int		j;

	j = -1;
	s1 = (char*)s;
	i = 0;
	while (s1[i])
	{
		if (s1[i] == (char)c)
			j = i;
		i++;
	}
	if ((char)c == '\0')
	{
		return (s1 + i);
	}
	if (j != -1)
		return (s1 + j);
	return (NULL);
}
