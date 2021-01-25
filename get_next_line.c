/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcho <zytls92@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 04:02:46 by mcho              #+#    #+#             */
/*   Updated: 2021/01/25 20:55:30 by mcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int					get_line(char **line, char **temp)
{
	int				nl_pos;
	int				eof_pos;

	nl_pos = -1;
	eof_pos = -1;
	if (*temp == NULL)
	{
		//*line = ft_strdup("");
		return (0);
	}
	ft_strchr(*temp, &nl_pos, &eof_pos);
	if (nl_pos == -1)
	{
		*line = ft_strdup(*temp);
		return (0);
	}
	*line = ft_substr(*temp, 0, nl_pos, 0);
	*temp = ft_substr(*temp, nl_pos + 1, eof_pos - nl_pos - 1, 1);
	return (1);
}

int					is_nullornew(char *s)
{
	int				idx;

	idx = 0;
	while (idx < BUFFER_SIZE)
	{
		if (s[idx] == '\0' || s[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

int					get_next_line(int fd, char **line)
{
	static char		*temp;
	char			*buf;
	int				read_size;
	int				res;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if ((buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))) == NULL)
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		temp = ft_strjoin(temp, buf);
		if (is_nullornew(buf) != -1)
			break ;
	}
	free(buf);
	if (read_size == -1)
		return (-1);
	res = get_line(line, &temp);
	if (res == 0)
	{
		free(temp);
		temp = 0;
	}
	return (res);
}
