/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:04:19 by ghambrec          #+#    #+#             */
/*   Updated: 2024/11/02 19:52:20 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// create new buffer joining both buffer and read_buffer,
// after that free the old buffer
char	*join_new_buffer(char *buffer, char *read_buffer)
{
	char	*new_buffer;

	if (!buffer)
	{
		return (ft_strdup(read_buffer));
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
		return (free(*buffer), *buffer = NULL, NULL);
	ft_strlcpy(returnline, *buffer, len + 1);
	new_buffer = (char *)malloc((ft_strlen(*buffer) - len + 1) * sizeof(char));
	if (!new_buffer)
	{
		free(returnline);
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	ft_strlcpy(new_buffer, *buffer + len, ft_strlen(*buffer) - len + 1);
	free(*buffer);
	*buffer = new_buffer;
	return (returnline);
}

char	*get_next_line(int fd)
{
	static char	*buffer[2000];
	char		read_buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	if (fd < 0 || fd >= 2000 || BUFFER_SIZE < 0)
		return (NULL);
	bytes_read = read(fd, read_buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		read_buffer[bytes_read] = '\0';
		buffer[fd] = join_new_buffer(buffer[fd], read_buffer);
		if (!buffer[fd])
			return (NULL);
		if (ft_strchr(buffer[fd], '\n'))
			return (return_line(&buffer[fd]));
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
	}
	if (bytes_read < 0 || !buffer[fd] || !*buffer[fd])
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	return (return_line(&buffer[fd]));
}

// #include <stdio.h>
// int	main(void)
// {
// 	int fd = open("test.txt",O_RDONLY);
// 	int fd2 = open("test2.txt",O_RDONLY);
// 	char *val;
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd2));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd2));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd2));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd2));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd2));
// 	return(0);
// }
