/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitadorofeychik <nikitadorofeychik@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:21:01 by ndorofey          #+#    #+#             */
/*   Updated: 2025/02/02 14:48:04 by nikitadorof      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_text(int fd, char *text)
{
	char	*new_text;
	int			size;

	if (ft_end_file(text) == 1)
		return (text);
	new_text = malloc(sizeof(char) * (BUFFER_SIZE +1));
	if (!new_text)
		return (free(text), NULL);
	size = read(fd, new_text, BUFFER_SIZE);
	if (size < 0)
		return (free(new_text), free(text), NULL);
	new_text[size] = '\0';
	if (size == 0)
		return (free(new_text), text);
	text = ft_join_to_me(text, new_text, size);
	if (!text)
		return (free(new_text), NULL);
	if (ft_end_file(new_text) == 0)
		text = ft_get_text(fd, text);
	free(new_text);
	return (text);
}
char	*ft_get_line(char *text)
{
	char	*line;
	int			iter;
	int			z;

	iter = 0;
	while (text[iter] && text[iter] != '\n')
		iter++;
	if (text[iter] == '\n')
		iter++;
	line = malloc(sizeof(char) * (iter + 1));
	if (!line)
		return (free(text), NULL);
	z = 0;
	while (z < iter)
	{
		line[z] = text[z];
		z++;
	}
	line[z] = '\0';
	return (line);
}

char *get_next_line (int fd)
{
	char		*text;
	char		*line;
	static char	*save;

	if (fd < 0 )
		return (NULL);
	text = get_text(fd, save);
	if (text == NULL)
		return (save = NULL, NULL);
	line = get_line(text);
	if (text == NULL)
		return (save =NULL, NULL);
	save = get_save(text);
	return (line);
}

char	*ft_get_save(char *text, int *info)
{
	char	*save;
	int				start;
	int				size;
	int				i;

	start = ft_strlen(text, '\n');
	if (text[start] == '\n')
		start++;
	size = 0;
	while (text[start + size])
		size++;
	if (size == 0)
		return (free(text), NULL);
	save = malloc(sizeof(char) * (size + 1));
	if (!save)
		return (*info = -1, free(text), NULL);
	i = 0;
	while (i < size)
	{
		save[i] = text[start + i];
		i++;
	}
	save[i] = '\0';
	free(text);
	return (save);
}
int	main(void)
{
	int	fd;
	char *str;

	fd = open("test.txt", O_RDONLY);
	while(1)
	{
		str = get_next_line(fd);
		printf ("line: %s\n", str);
		free (str);
		if (str = NULL)
			break ;
	}
	return (0);
}