/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marferre <marferre@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:21:17 by marferre          #+#    #+#             */
/*   Updated: 2022/10/12 10:27:28 by marferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/*Main function*/
char	*get_next_line(int fd);

/*Utils*/
int		ft_strlen(char const *str);
char	*ft_strchr(char const *str, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif