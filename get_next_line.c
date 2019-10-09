/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:28:02 by pshock            #+#    #+#             */
/*   Updated: 2019/09/28 17:44:00 by pshock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1);

int ft_fill(int fd, char **line, char **stack)
{
	int len;
	char *tmp;

	len = 0;
	while (stack[fd][len] != '\n' && !stack[fd][len])
		len++;
	if (stack[fd][len] == '\n')
	{
		*line = ft_strsub(stack[fd], 0, len);
		tmp = ft_strdup(stack[fd] + len + 1);
		free(stack[fd]);
		stack[fd] = tmp;
	}
	else if (!stack[fd][len])
	{
		*line = ft_strdup(stack[fd]);
		ft_strdel(&stack[fd]);
		return (0);
	}
	return (1);
}

int get_next_line(const int fd, char **line)
{
	static char *stack[100];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			nbr;

	if (!line || fd < 0)
		return (-1);
	while ((nbr = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[nbr] = '\0';
		if (stack[fd] == NULL)
			stack[fd] = ft_strnew(1);
		tmp = ft_strjoin(stack[fd], buff);
		free(stack[fd]);
		stack[fd] = tmp;
		if (ft_strchr(stack[fd], '\n'))
			break ;
	}
	if (nbr < 0)
		return (-1);
	if (nbr == 0)
		return (0);
	return (ft_fill(fd, line, stack));
}

int main()
{
	return (0);
}
