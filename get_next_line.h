/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndorofey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:21:47 by ndorofey          #+#    #+#             */
/*   Updated: 2025/01/22 16:00:16 by ndorofey         ###   ########.fr       */
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
char *ft_strcat(char *s1, char *s2)
char *ft_strchr(char *save, int character)
void *ft_calloc(unsigned long int size, unsigned long int c)
void ft_bzero(void *str, unsigned long int n)
unsigned long int ft_strlen(char *s)
#endif
