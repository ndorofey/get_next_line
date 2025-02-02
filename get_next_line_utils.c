/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitadorofeychik <nikitadorofeychik@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:21:27 by ndorofey          #+#    #+#             */
/*   Updated: 2025/02/02 15:01:25 by nikitadorof      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str,char type)
{
	int		i;

	if (!str)
			return (0);
	i = 0;
	while (str[i] && str[i] != type)
			i++;
	return (i);
}

char	*ft_join_to_me(char *line, char *step, int len)
{
	char	*alpha;
	int				i;
	int				j;
	int				size;

	size =ft_strlen(line, '\0');
	alpha = malloc(sizeof(char) * (size + len + 1));
	if (!alpha)
			return (free(line), NULL);
	i = 0;
	while (i < size)
	{
		alpha[i] = line[i];
		i++;
	}
	j = 0;
	while (i < size + len)
			alpha[i++] = step[j++];
	alpha[i] = '\0';
	free(line);
	return (alpha);
}
int		ft_end_file(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
				return (1);
		i++;
	}
	return (0);
}