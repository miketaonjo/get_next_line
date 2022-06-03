/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:25:48 by mcloarec          #+#    #+#             */
/*   Updated: 2022/05/02 17:51:32 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_save_line(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	str = ft_calloc(sizeof(char), (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (line[i] != '\0' && line[i] != '\n')
		str[j++] = line[i++];
	if (line[i] == '\n')
		str[j++] = '\n';
	return (str);
}

char	*ft_move_to_line(char *line)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	s = ft_calloc(sizeof(char), (ft_strlen(line) - i + 1));
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (line[i] != '\0')
		s[j++] = line[i++];
	free(line);
	return (s);
}

char	*ft_read_line(int fd, char *line)
{
	char	*buffer;
	int		i;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	i = 1;
	while (ft_strchr(line, '\n') != 1 && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		buffer[i] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line[1000];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (line[fd] == NULL)
	{
		line[fd] = ft_calloc(sizeof(char), 1);
		if (!line[fd])
			return (NULL);
	}
	line[fd] = ft_read_line(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	result = ft_save_line(line[fd]);
	line[fd] = ft_move_to_line(line[fd]);
	return (result);
}
