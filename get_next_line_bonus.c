/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-fihr <mel-fihr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:01:40 by mel-fihr          #+#    #+#             */
/*   Updated: 2023/12/24 10:38:37 by mel-fihr         ###   ########.fr       */
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
	static char	*line[OPEN_MAX];
	char		*new_line;
	char		*tmp;
	int			i;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || read(fd, line, 0) < 0)
		return (free(line[fd]), line[fd] = NULL, NULL);
	i = 0;
	line[fd] = ft_read(line[fd], fd);
	if (!line[fd] || !*line[fd])
		return (free(line[fd]), line[fd] = NULL, NULL);
	while (line[fd][i] != '\n' && line[fd][i])
		i++;
	if (line[fd][i] == '\n')
		i++;
	new_line = (char *)malloc(i + 1);
	if (!new_line)
		return (free(line[fd]), line[fd] = NULL, NULL);
	new_line = ft_line(line[fd], new_line);
	return (new_line[i] = '\0', tmp = ft_strdup(line[fd] + i),
		free(line[fd]), line[fd] = ft_strdup(tmp), free(tmp), new_line);
}
