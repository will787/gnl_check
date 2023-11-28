#include "get_next_line.h"

void	finallylist(t_list **list)
{
	t_list	*last_node;
	t_list	*newbufferbreakln;
	int		i;
	int		j;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	newbufferbreakln = malloc(sizeof(t_list));
	if (!buffer || !newbufferbreakln)
		return ;
	last_node = ft_lstlast(*list);
	j = 0;
	i = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
			i++;
	while (last_node->content[i] && last_node->content[++i])
		buffer[j++] = last_node->content[i]; 
	buffer[j] = '\0';
	free_list(*list);
	newbufferbreakln->content = buffer;
	newbufferbreakln->next = NULL;
	*list = newbufferbreakln;
}

char	*outside_line(t_list *list)
{
	int		lenline;
	char	*str;

	if (!list)
		return (NULL);
	lenline = countnewline(list);
	str = malloc(lenline + 1);
	if (!str)
		return (NULL);
	copy_line(list, str);
	return (str);
}

void    ft_add(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_lstlast(*list);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (!last_node)
	{
		*list = new_node;
	}
	else
	{
		last_node-> next = new_node;
	}
	new_node->content = buffer;
	new_node->next = NULL;
}

void    ft_createnode(t_list **list, int fd)
{
	int		char_read;
	char	*buffer;

	char_read = 1;
	while(!new_line(*list) && char_read != 0)
	{   
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		char_read = read(fd, buffer, BUFFER_SIZE);
		if ((!char_read && list == NULL) || char_read < 0)
		{   
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		ft_add(list, buffer);
	}
}

char    *get_next_line(int fd)
{
	static	t_list *list;	
	char	*line_actual;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, &line_actual, 0) < 0)
	{
		free_list(list);
		list = NULL;
		return (NULL);
	}
	line_actual = (NULL);
	ft_createnode(&list, fd);
	if (!list)
		return (NULL);
	line_actual = outside_line(list);
	finallylist(&list);
	if (line_actual[0] == '\0')
	{
		free_list(list);
		list = NULL;
		free(line_actual);
		return (NULL);
	}
	return (line_actual);
}

int main()
{
	int char_read;
	char *line;
	int fd = open("teste.txt", O_RDWR);

	// line = get_next_line(fd);
	// printf("%s", line);
	if (fd < 0)
	{
		printf("Erro ao abrir o arquivo\n");
		return 1;
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	printf("\n");
	close(fd);
	return 0;
}