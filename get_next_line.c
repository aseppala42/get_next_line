/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseppala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:47:07 by aseppala          #+#    #+#             */
/*   Updated: 2019/11/21 18:15:44 by aseppala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
int		get_next_line(const int fd, char **line)
{
	static char	*next = 0;
	char		buf[BUFF_SIZE + 1];
	int			ret;
	int			len;
	
	if (line == 0)
		return (-1);
	if (next == 0)
		if ((next = ft_memalloc(1)) == 0)
			return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		len = ft_strlen(next) + ft_strchrlen(buf, '\n') + 1;
		if ((next = ft_realloc(next, ft_strlen(next), len)) == 0)
			return (-1);
		ft_strlcat(next, buf, len);
		if (ft_strchrlen(buf, '\n') < ft_strlen(buf))
			break ;
	}
	if (ret == -1)
	{
		next = 0;
		return (-1);
	}
	*line = next;
	if (ft_strchrlen(buf, '\n') < ft_strlen(buf))
		next = ft_strsub(buf, ft_strchrlen(buf, '\n') + 1, ft_strlen(buf) - ft_strchrlen(buf, '\n'));
	else
		next = 0;
	return (**line == 0 ? 0 : 1);
}


int		get_next_line(const int fd, char **line)
{
	static char	**next = 0;
	char		buf[BUFF_SIZE + 1];
	int			ret;
	
	if (line == 0)
		return (-1);
	if (next != 0 && *next != 0)
	{
		*line = *next;
		next++;
		return (1);
	}
	ret = read(fd, buf, BUFF_SIZE);
	if (ret == 0 || ret == -1)
		return (ret);
	buf[ret] = 0;
	next = ft_strsplit(buf, '\n');
	return (get_next_line(fd, line));
}

int		get_next_line(const int fd, char **line)
{
	static char	**next = 0;
	char		buf[BUFF_SIZE + 1];
	int			ret;
	
	if (line == 0)
		return (-1);
	if (next != 0 && *(next + 1) != 0)
	{
		*line = *next;
		next++;
		return (1);
	}
	if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	if (ret == 0)
	{
		*line = *next;
		ft_strdel(next);
		return (*line ? 1 : 0);
	}
	buf[ret] = 0;
	if (next != 0)
		*next = ft_strjoindel(*next, ft_strdup(buf));
	next = ft_strsplit((next ? *next : buf), '\n'); // split poistaa vikan nl jos se on sattumalta juuri ennen nullia
	return (get_next_line(fd, line));
}
*/
int		get_next_line(const int fd, char **line)
{
	static char	*next = 0;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;
	
	if (line == 0)
		return (-1);
	if (next != 0 && ft_strchr(next, '\n'))
	{
		*line = ft_strndup(next, ft_strchrlen(next, '\n'));
		tmp = ft_strdup(ft_strchr(next, '\n') + 1);
		ft_strdel(&next);
		next = tmp;
		return (1);
	}
	if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	if (ret == 0)
	{
		if (next != 0)
		{
			*line = ft_strdup(next);
			ft_strdel(&next);
			return (1);
		}
		return (0);
	}
	buf[ret] = 0;
	next = ft_strjoindel(next, ft_strdup(buf));
	return (get_next_line(fd, line));
}
/*
int		get_next_line(const int fd, char **line)
{
	static char	*next = 0;
	char		buf[BUFF_SIZE + 1];
	int			ret;
	
	if (line == 0)
		return (-1);
	if (next == 0)
		if ((next = ft_memalloc(1)) == 0)
			return (-1);
	ret = read(fd, buf, BUFF_SIZE);
	if (ret == 0 || ret == -1)
	{
		next = 0;
		return (ret);
	}
	buf[ret] = 0;
	if ((next = ft_realloc(next, ft_strlen(next), ft_strlen(next) + 
					ft_strchrlen(buf, '\n') + 1)) == 0)
		return (-1);
	ft_strlcat(next, buf, ft_strlen(next) + ft_strchrlen(buf, '\n') + 1);
	*line = next;
	if (ft_strchrlen(buf, '\n') < ft_strlen(buf))
		next = ft_strsub(buf, ft_strchrlen(buf, '\n') + 1, ft_strlen(buf) - 
				ft_strchrlen(buf, '\n'));
	else
		get_next_line(fd, line);
	return (**line == 0 ? 0 : 1);
}*/
