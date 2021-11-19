/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:32:34 by bberkass          #+#    #+#             */
/*   Updated: 2021/11/19 14:06:20 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	nl_in(char *s)
{
	int i;

	if(!s)
		return (0);
	i = 0;
	while(s[i])
	{
		if(s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*rest;
	int			readed;
	char		*tmp;

	line = NULL;
	rest = NULL;
	readed = 1;
	buff = (char *)calloc(sizeof(char), BUFFER_SIZE + 1);
	if(rest && nl_in(rest))
	{
		line = get_line(rest);
		tmp = rest;
		rest = get_rest(rest);
		free(tmp);
		free(buff);
		return (line);
	}
	while(readed > 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if(readed == -1)
		{
			free(buff);
			free(rest);
			return (NULL);
		}
		else if(readed > 0)
		{
			buff[readed] = '\0';
			tmp = rest;
			rest = ft_strjoin(rest, buff);
			free(tmp);
			if(nl_in(rest))
				break;
		}
	}
	free(buff);
	if(rest)
	{
		line = get_line(rest);
		tmp = rest;
		rest = get_rest(rest);
		free(tmp);
		if(ft_strlen(rest) == 0 || readed == 0)
			free(rest);
	}
	return (line);
}
