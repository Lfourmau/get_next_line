/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:30:39 by loic              #+#    #+#             */
/*   Updated: 2020/12/11 10:19:19 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char		*ft_strjoin(char const *prefixe, char const *suffixe)
{
	char	*concat;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!prefixe && !suffixe)
		return (NULL);
	len = ft_strlen(prefixe) + ft_strlen(suffixe);
	if (!(concat = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < ft_strlen(prefixe))
	{
		concat[i] = prefixe[i];
		i++;
	}
	while (j < ft_strlen(suffixe))
	{
		concat[i + j] = suffixe[j];
		j++;
	}
	concat[len] = 0;
	free((char *)prefixe);
	return (concat);
}

int			ft_isline_break(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;

	i = 0;
	if (src == 0)
		return (0);
	while (src[i] && i < size - 1)
	{
		if (size > 0)
		{
			dest[i] = src[i];
		}
		i++;
	}
	if (size > 0)
		dest[i] = 0;
	while (src[i])
		i++;
	return (dest);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	if (len < 0)
		len *= -1;
	result = malloc(sizeof(char) * len + 1);
	if (result == NULL || s == 0)
		return (NULL);
	i = 0;
	if (start >= (unsigned int)ft_strlen(s))
	{
		result[i] = 0;
		return (result);
	}
	s += start;
	while (*s && i < len)
	{
		result[i] = *s;
		i++;
		s++;
	}
	result[i] = 0;
	return (result);
}
