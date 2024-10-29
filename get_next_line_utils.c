/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:04:12 by ghambrec          #+#    #+#             */
/*   Updated: 2024/10/29 16:36:56 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	size_t	i;
	char	*dup;

	i = 0;
	len = ft_strlen(str);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
	{
		return (NULL);
	}
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*res;

	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	i = 0;
	while (*s1)
	{
		res[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		res[i] = *s2;
		s2++;
		i++;
	}
	return (res);
}

// static int	calc_len_substr(size_t strlen, size_t start, size_t len)
// {
// 	size_t	substrlen;

// 	if (start >= strlen)
// 	{
// 		return (0);
// 	}
// 	if (len < strlen - start)
// 	{
// 		substrlen = len;
// 	}
// 	else
// 	{
// 		substrlen = strlen - start;
// 	}
// 	return (substrlen);
// }

// char	*ft_substr(char const *str, unsigned int start, size_t len)
// {
// 	size_t	strlen;
// 	size_t	substrlen;
// 	size_t	i;
// 	char	*substr;

// 	if (!str)
// 		return (NULL);
// 	strlen = ft_strlen(str);
// 	substrlen = calc_len_substr(strlen, start, len);
// 	substr = (char *)malloc((substrlen + 1) * sizeof(char));
// 	if (substr == NULL)
// 		return (NULL);
// 	if (start >= strlen)
// 	{
// 		substr[0] = '\0';
// 		return (substr);
// 	}
// 	i = 0;
// 	while (i < substrlen && str[start])
// 	{
// 		substr[i] = str[start];
// 		start++;
// 		i++;
// 	}
// 	return (substr[i] = '\0', substr);
// }

char	*ft_strchr(const char *str, int c)
{
	char	ch;

	ch = (char)c;
	while (*str != '\0')
	{
		if (*str == ch)
		{
			return ((char *)str);
		}
		str++;
	}
	if (ch == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}

