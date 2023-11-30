/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivieira <wivieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:59:46 by wivieira          #+#    #+#             */
/*   Updated: 2023/11/30 13:59:46 by wivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h> 
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
char	*outside_line(t_list *list);
void	ft_createnode(t_list **list, int fd);
void	ft_add(t_list **list, char *buffer);
void	copy_line(t_list *list, char *str);
void	finallylist(t_list **list);
void	free_list(t_list *list);
int		new_line(t_list *list);
int		countnewline(t_list *list);
t_list	*ft_lstlast(t_list *list);
#endif