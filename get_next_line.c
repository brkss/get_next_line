/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:32:34 by bberkass          #+#    #+#             */
/*   Updated: 2021/11/20 03:07:24 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	nl_in(char *s)
{
	int i;

	if(s == 0)
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

	line = NULL;
	readed = 1;
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	while(!nl_in(rest) && readed > 0)
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
			rest = ft_strjoin(rest, buff);
			if(nl_in(rest))
				break;
		}
	}
	free(buff);
	if(rest)
	{
		line = get_line(rest);
		rest = get_rest(rest);
		if(!rest)
			free(rest);
	}
	return (line);
}
