/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:01:40 by mel-fihr          #+#    #+#             */
/*   Updated: 2023/12/22 19:40:58 by mel-fihr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_line(char *line, char *new_line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		new_line[i++] = '\n';
	return (new_line);
}

static char	*ft_read(char *line, int fd)
{
	int		ret;
	char	*buff;

	ret = 1;
	while (ret)
	{
		buff = (char *)malloc((size_t)BUFFER_SIZE + 1);
		if (!buff)
			return (free(line), NULL);
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == 0)
			return (free(buff), buff = NULL, line);
		buff[ret] = '\0';
		line = ft_strjoin(line, buff);
		free(buff);
		if (!line)
			return (NULL);
		if (ft_strchr(line, '\n'))
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char		*new_line;
	char		*tmp;
	int			i;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || read(fd, line, 0) < 0)
		return (free(line), line = NULL, NULL);
	i = 0;
	line = ft_read(line, fd);
	if (!line || !*line)
		return (free(line), line = NULL, NULL);
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	new_line = (char *)malloc(i + 1);
	if (!new_line)
		return (free(line), line = NULL, NULL);
	new_line = ft_line(line, new_line);
	return (new_line[i] = '\0', tmp = ft_strdup(line + i),
		free(line), line = ft_strdup(tmp), free(tmp), new_line);
}
