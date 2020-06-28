/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:54:24 by iaduquen          #+#    #+#             */
/*   Updated: 2019/12/19 18:49:25 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*str;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (i < len && s[start])
			str[i++] = s[start++];
	}
	str[i] = 0;
	return (str);
}

size_t	ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != c)
	{
		if (str[i] == 0)
			return (0);
		i++;
	}
	i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	if (s1)
		len = ft_strlen(s1);
	else
		len = 0;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * ((ft_strlen(s1) +
							ft_strlen(s2) + 1)))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	if (s1)
		free(s1);
	return (str);
}
