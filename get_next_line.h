/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcho <mcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:19:00 by mcho              #+#    #+#             */
/*   Updated: 2020/11/11 14:41:59 by mcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <ctype.h>
# include <fcntl.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
char	*ft_substr(char const *s, unsigned int start, int len, int flag);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
void	ft_strchr(char *s, int *nl_pos, int *eof_pos);
int		ft_strlen(char *s);

#endif
