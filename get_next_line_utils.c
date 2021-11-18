/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:34:30 by bberkass          #+#    #+#             */
/*   Updated: 2021/11/18 23:01:11 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *s)
{
	int	l;

	l = 0;
	while(s[l])
		l++;
	return (l);
}

char	*get_line(char *s)
{
	char	*line;
	int		i;

	i = 0;
	// get line length 
	while(s[i] && s[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if(!line)
		return (NULL);
	i = 0;
	while(s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_rest(char *s)
{
	char	*rest;
	int		i;
	int		s_len;
	int		j;

	j = 0;
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] && s[i] == '\n')
		i++;
	s_len = ft_strlen(&s[i]) + 1;
	rest = (char *)malloc(sizeof(char) * s_len);
	if(!rest)
		return (NULL);
	while(s[i])
	{
		rest[j] = s[i];
		i++;
		j++;
	}
	rest[j] = '\0';
	return (rest);
}
