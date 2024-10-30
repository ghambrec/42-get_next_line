/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:04:19 by ghambrec          #+#    #+#             */
/*   Updated: 2024/10/30 16:28:27 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

// create new buffer joining both buffer and read_buffer, after that free the old buffer
char	*join_new_buffer(char *buffer, char *read_buffer)
{
	char	*new_buffer;

	if (!buffer)
	{
		return(ft_strdup(read_buffer));
	}
	new_buffer = ft_strjoin(buffer, read_buffer);
	free(buffer);
	return (new_buffer);
}

// return line and renew the buffer
char	*return_line(char **buffer)
{
	char	*returnline;
	char	*new_buffer;
	size_t	len;

	if (ft_strchr(*buffer, '\n'))
		len = (ft_strchr(*buffer, '\n') - *buffer) + 1;
	else
		len = ft_strlen(*buffer);
	returnline = (char *)malloc((len + 1) * sizeof(char));
	if (!returnline)
		return (NULL);
	ft_strlcpy(returnline, *buffer, len + 1);
	new_buffer = (char *)malloc((ft_strlen(*buffer) - len + 1) * sizeof(char));
	if (!new_buffer)
	{
		free(returnline);
		return (NULL);
	}
	ft_strlcpy(new_buffer, *buffer + len, ft_strlen(*buffer) - len + 1);
	free(*buffer);
	*buffer = new_buffer;
	return (returnline);
}


char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		read_buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	while ((bytes_read = read(fd, read_buffer, BUFFER_SIZE)) > 0)
	{
		read_buffer[bytes_read] = '\0';
		buffer = join_new_buffer(buffer, read_buffer);
		if (!buffer)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
		{
			return (return_line(&buffer));
		}
	}
	if (bytes_read < 0 || !buffer || !*buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);	
	}
	return (return_line(&buffer));
}

// int	main(void)
// {
// 	int fd = open("test.txt",O_RDONLY);
// 	char *val;
// 	if (fd == -1)
// 		printf("error opening file\n");
// 	else
// 	{
// 		while ((val = get_next_line(fd)))
// 		{
// 			printf("%s", val);
// 			free(val);
// 		}
// 		close(fd);
// 	}
		
// 	return(0);
// }
