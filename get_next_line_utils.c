/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:34:30 by bberkass          #+#    #+#             */
/*   Updated: 2021/11/19 22:23:06 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *s)
{
	int	l;

	l = 0;
	while(s[l])
		l++;
	return (l);
}

char	*ft_strdup(const char *s1)
{
	char			*dup;
	unsigned int	i;
	unsigned int	sl;

	i = 0;
	sl = ft_strlen(s1);
	dup = (char *)malloc(sl + 1 * sizeof(char));
	if (!dup)
		return (0);
	while (s1[i] && i < sl)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*get_line(char *s)
{
	char	*line;
	int		i;

	i = 0;
	// get line length 
	while (s[i] && s[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] = '\n';
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

char	*ft_strcat(char *dest, const char *s1, const char *s2)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s1[i])
	{
		dest[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		dest[j] = s2[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		s1_length;
	int		s2_length;

	if (!s1 && !s2)
		return (0);
	if(!s1)
		return (ft_strdup(s2));
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	joined = (char *)malloc((s1_length + s2_length + 1) * sizeof(char));
	if (!joined)
		return (0);
	if (!joined)
		return (0);
	joined = ft_strcat(joined, s1, s2);
	return (joined);
}
