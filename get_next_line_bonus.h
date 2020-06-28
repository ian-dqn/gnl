/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:49:50 by iaduquen          #+#    #+#             */
/*   Updated: 2019/12/19 18:49:53 by iaduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen_bonus(const char *str);
char	*ft_strdup_bonus(char *s1);
char	*ft_strjoin_bonus(char *s1, char *s2);
char	*ft_substr_bonus(char const *s, unsigned int start, size_t len);
size_t	ft_strchr_bonus(const char *str, int c);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif
