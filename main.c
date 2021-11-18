/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:34:43 by bberkass          #+#    #+#             */
/*   Updated: 2021/11/18 23:00:06 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	int fd = open("file.txt", O_RDWR | O_RDONLY);
	char *s = "this is a line \n this is the rest \n i know another line lines  ! \n";
	printf("line => %s \n", get_line(s));	
	printf("rest => %s \n", get_rest(s));	
	return (0);
}
