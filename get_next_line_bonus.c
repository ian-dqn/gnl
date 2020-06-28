/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:47:40 by iaduquen          #+#    #+#             */
/*   Updated: 2019/12/19 23:44:24 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_free_4_all(char *s)
{
	if (s)
		free(s);
	return (-1);
}

char	*ft_strcpy(char *dst, char *src, size_t n)
{
	size_t	i;
	size_t	j;

	if (!(dst = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	if (src)
		free(src);
	return (dst);
}

char	*ft_read(int fd, char *line)
{
	int		ret;
	char	buf[BUFFER_SIZE + 1];
	int		i;

	i = 0;
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (ret == -1)
			return (NULL);
		buf[ret] = 0;
		i++;
		if (!(line = ft_strjoin_bonus(line, buf)))
			return (NULL);
		if (ft_strchr_bonus(line, '\n'))
		{
			return (line);
		}
	}
	return (line);
}

int		get_next_line(int fd, char **line)
{
	static char *s[OPEN_MAX];
	size_t		i;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > FOPEN_MAX || !line)
		return (-1);
	i = 0;
	if (!(*line = ft_strdup_bonus(s[fd])))
		return (-1);
	if (s[fd])
		s[fd][0] = 0;
	if (!(ft_strchr_bonus(*line, '\n')))
		if (!(*line = ft_read(fd, *line)))
			return (ft_free_4_all(*line));
	if (!(i = ft_strchr_bonus(*line, '\n')))
		return (0);
	if (s[fd])
		free(s[fd]);
	if (!(s[fd] = ft_substr_bonus(*line, i, ft_strlen_bonus(*line))))
		return (ft_free_4_all(*line));
	if (!(*line = ft_strcpy(*line, *line, i - 1)))
	{
		free(*line);
		return (ft_free_4_all(*s));
	}
	return (1);
}
