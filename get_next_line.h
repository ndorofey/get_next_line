/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitadorofeychik <nikitadorofeychik@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:21:47 by ndorofey          #+#    #+#             */
/*   Updated: 2025/02/02 15:02:18 by nikitadorof      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_get_save(char *text, int *info);
char	*ft_get_line(char *text);
char	*ft_get_text(int fd, char *text);
char	*ft_join_to_me(char *line, char *step, int len);
int		ft_strlen(char *str,char type);
int		ft_end_file(char *str);
#endif
