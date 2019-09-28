/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:54:56 by pshock            #+#    #+#             */
/*   Updated: 2019/09/17 12:40:14 by pshock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	int			negative;
	long long	result;
	long long	temp;

	negative = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		temp = (result * 10) + (*str++ - '0');
		if (result > temp)
		{
			if (negative == 1)
				return (-1);
			return (0);
		}
		result = temp;
	}
	return ((int)(result * negative));
}
