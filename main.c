/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:29:14 by aseppala          #+#    #+#             */
/*   Updated: 2019/11/21 11:51:13 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void		opener(int ac, char **av, char *line)
{
	int		fd;
	int		res;

	while (ac-- > 1)
	{
		av++;
		if ((fd = open(*av, O_RDONLY)) == -1)
			printf("not cool man, couldn't open the file\n");
		while ((res = get_next_line(fd, &line)))
			printf("%d\t%s\n", res, line);
		if (close(fd) == -1)
			printf("shieet, couldn't close the file\n");
		printf("\n\n");
	}
}

int			main(int ac, char **av)
{
	char	*line;

	line = 0;
	if (ac > 1)
		opener(ac, av, line);
	else
		while (get_next_line(0, &line))
			printf("%s\n", line);
	return (0);
}
