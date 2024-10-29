/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:04:19 by ghambrec          #+#    #+#             */
/*   Updated: 2024/10/29 17:43:43 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif



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
		// buffer = ft_strjoin(buffer, read_buffer);
		// TODO: join into new buffer + free the old one
		// printf("[%s]", read_buffer);
		if (ft_strchr(buffer, '\n'))
		{
			// TODO: return the line until the NL + renew the buffer
			printf("***");
			break;
		}
	}
	
	return (NULL);
}



int	main(void)
{
	int fd = open("test.txt",O_RDONLY);
	char *val;
	if (fd == -1)
		printf("error opening file\n");
	else
	{
		get_next_line(fd);
		// get_next_line(fd);
		// while (val = get_next_line(fd))
		// {
		// 	printf("%s", val);
		// 	// free(val);
		// }
		close(fd);
	}
		
		
	return(0);
}
