/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:03:44 by mel-fihr          #+#    #+#             */
/*   Updated: 2023/12/24 10:13:48 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s++ == (char)c)
			return (1);
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	str = (char *) malloc(ft_strlen(s1) + 1);
	if (!str)
		return (free(str), str = NULL, NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
	{
		free(s1);
		return (s1 = NULL, NULL);
	}
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
	return (str[i + j] = 0, free(s1), s1 = NULL, str);
}
