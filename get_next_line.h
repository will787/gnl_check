#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

typedef struct s_list
{
    char *content;
    struct s_list *next; 
}   t_list;

char    *get_next_line(int fd);
char    *outside_line(t_list *list);
void    ft_createnode(t_list **list, int fd);
void    ft_add(t_list **list, char *buffer);
void 	copy_line(t_list *list, char *str);
void finallylist(t_list **list);
void	free_list(t_list *list);
int     new_line(t_list *list);
int     countnewline (t_list *list);
t_list  *ft_lstlast(t_list *list);
#endif