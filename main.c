/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:34:43 by bberkass          #+#    #+#             */
/*   Updated: 2021/11/20 12:58:39 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	char s[200];
	read(0, s, 200);
	printf("s => %s \n", s);
	/*
	int fd = open("43_with_nl", O_RDWR | O_RDONLY);
	//char *s = "this is a line \n this is the rest \n i know another line lines  ! \n";
	//printf("line => %s \n", get_line(s));	
	//char *rest = get_rest(s);
	//printf("rest => %s \n", rest);	
	printf("=> %s", get_next_line(fd));
	printf("=> %s", get_next_line(fd));
	printf("=> %s", get_next_line(fd));
	printf("=> %s", get_next_line(fd));
	printf("=> %s", get_next_line(fd));
	printf("=> %s", get_next_line(fd));
	printf("=> %s", get_next_line(fd));
	printf("=> %s", get_next_line(fd));
	*/
	return (0);
}
