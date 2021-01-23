/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcho <mcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:19:23 by mcho              #+#    #+#             */
/*   Updated: 2021/01/24 04:13:02 by mcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int			ft_strlen(char *s)
{
	int		len;

	len = 0;
	if (!s)
		return (len);
	while (s[len])
		len++;
	return (len);
}

void		ft_strchr(char *s, int *nl_pos, int *eof_pos)
{
	int		idx;
	int		flag;

	idx = 0;
	flag = 0;
	while (s[idx])
	{
		if (s[idx] == '\n' && flag == 0)
		{
			*nl_pos = idx;
			flag = 1;
		}
		idx++;
	}
	*eof_pos = idx;
}

char		*ft_strdup(const char *s)
{
	char	*res;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (*(s + len) != '\0')
		len++;
	if ((res = malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		s1_s;
	int		s2_s;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 && s2)
		return (ft_strdup(s2));
	i = 0;
	s1_s = ft_strlen((char *)s1);
	s2_s = ft_strlen((char *)s2);
	if ((res = (char *)malloc(sizeof(char) * (s1_s + s2_s + 1))) == NULL)
		return (NULL);
	while (i < s1_s + s2_s)
	{
		if (i < s1_s)
			res[i] = s1[i];
		else
			res[i] = s2[i - s1_s];
		i++;
	}
	res[i] = '\0';
	free((char *)s1);
	return (res);
}

char		*ft_substr(char const *s, unsigned int start, int len, int flag)
{
	char	*res;
	int		i;

	if (!s)
		return (ft_strdup(""));
	if ((int)start >= ft_strlen((char *)s))
		return (ft_strdup(""));
	if ((res = malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[i + start])
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = '\0';
	if (flag == 1)
		free((char *)s);
	return (res);
}
