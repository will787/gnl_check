#include "get_next_line.h"

int	new_line(t_list *list)
{
	int	i;

	if	(!list)
		return(0);
	while(list)
	{
		i = 0;
		while(list -> content[i] && i < BUFFER_SIZE)
		{
			if (list -> content[i] == '\n')
				return (1);
			i++;
		}
		list = list -> next;
	}
	return (0);
}

t_list	*ft_lstlast(t_list *list)
{
	if (!list)
		return (NULL);
	while (list -> next)
	{
		list = list -> next;
	}
	return (list);
}

int	countnewline(t_list *list)
{
	int	i;
	int	count;

	count = 0;
	while(list)
	{	
		i = 0;
		while(list -> content[i])
		{
			if (list -> content[i] == '\n')
			{	
				count++;
				return (count);
			}
			count++;
			i++;
		}
		list = list -> next;
	}
	return (count);
}

void 	copy_line(t_list *list, char *str)
{
	int	i;
	int	k;

	k = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list-> content[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return ;
			}
			str[k++] = list->content[i++];
		}
		list = list -> next;
	}
	str[k] = '\0';
}

void	free_list(t_list *list)
{
	t_list	*current;
	t_list	*next;

	if (!list)
		return ; 
	current = list;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}