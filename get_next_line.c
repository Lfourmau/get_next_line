/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:32:14 by loic              #+#    #+#             */
/*   Updated: 2020/12/10 15:55:22 by loic             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*after_lb(char *str)
{
	char				*chain;
	unsigned int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	chain = ft_substr(str, i + 1, (ft_strlen(str) - i));
	free(str);
	return (chain);
}

char	*before_lb(char *str)
{
	int		i;
	char	*chain;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(chain = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	return (ft_strlcpy(chain, str, i + 1));
}

int		get_next_line(int fd, char **line)
{
	char			*tmp;
	static char		*buffer;
	int				read_return;

	read_return = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(tmp = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (!ft_isline_break(buffer) && read_return != 0)
	{
		if ((read_return = read(fd, tmp, BUFFER_SIZE)) == -1)
		{
			free(tmp);
			return (-1);
		}
		tmp[read_return] = '\0';
		buffer = ft_strjoin(buffer, tmp);
	}
	free(tmp);
	line[0] = before_lb(buffer);
	buffer = after_lb(buffer);
	if (read_return == 0)
		return (0);
	return (1);
}


#include <fcntl.h>
#include <stdio.h>
int		main(void)
{
	char	*line;
	int		fd;
	line = NULL;
	fd = open("hello.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	if (close(fd) == -1)
		return (-1);
	while (1)
		;
	return (0);
}