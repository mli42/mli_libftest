/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:15:39 by mli               #+#    #+#             */
/*   Updated: 2019/10/17 22:32:28 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

void	delete(void *content)
{
	printf("Delete: %s\n", content);
}

void	*fct(void *content)
{
	char *cont;

	cont = ft_strdup((char *)content);
	cont[0] += 2;
	return (cont);
}

void	print_lst(t_list *lst)
{
	while (lst)
	{
		printf("%s", lst->content);
		if (lst->next)
			printf(" -> ");
		lst = lst->next;
	}
	printf("\n");
}

void	*under_main(t_list *list, int this)
{
	int		i;
	t_list	*ele;
	void	(*del)(void *);

	del = &delete;

	i = -1;
	if (this == 0)
	{
		printf("	|| LIST DEL ONE: ||\n");
		if (list == NULL || list->next == NULL)
			ft_lstdelone(list, del);
		else
		{
			ele = list->next->next;
			ft_lstdelone(list->next, del);
			list->next = ele;
		}
	}
	if (this == 1)
	{
		printf("\n	|| LIST CLEAR: ||\n");
		if (list == NULL || list->next == NULL)
			ft_lstclear(&list, del);
		else
			ft_lstclear(&(list->next->next->next->next), del);

	}
	if (this == 2)
	{
		printf("\n	|| LIST SIZE & LAST: ||\n");
		printf("Size: %d\n", ft_lstsize(list));
		if (ft_lstlast(list))
			printf("The Last One: %s\n", ft_lstlast(list)->content);
	}
	if (this == 3)
	{
		printf("\n	|| LIST MAP + 2: ||\n");
		list = ft_lstmap(list, &fct, del);
		print_lst(list);
	}
	if (this == 4)
	{
		printf("\n	|| LIST ITER (Just print): ||\n");
		ft_lstiter(list, del);
	}
	return (list);
}

int		main(void)
{
	int i = -1;
	t_list	*ele;
	t_list	*list = NULL;
	char	*str[] = {"0", "1", "2", "3", "4", "5", "6", NULL};

	//		Creating list
	printf("\n\t\t||\tCreating  [...]\t||\n");
	printf("\t\t||        Using         ||\n");
	printf("\t\t||   lst new + add f/b  ||\n\n");
	while (str[++i] != NULL)
	{
		ele = ft_lstnew(str[i]);
		ft_lstadd_back(&list, ele);
		print_lst(list);
	}
	ft_lstadd_front(&list, ft_lstnew("A"));
	ft_lstadd_front(&list, NULL);
	print_lst(list);
	printf("\n		|| Successfully created ||\n\n");
	// 		Created

	//		Testing
	i = -1;
	while (++i <= 4)
	{
		list = under_main(list, i);
		if (i != 3)
			print_lst(list);
	}
	/*
	 * 0 => List del one
	 * 1 => List clear
	 * 2 => Last & Size
	 * 3 => List map + 2
	 * 4 => List iter
	 *
	 * Tests with NULL;
	 */
	printf("\n		|| Successfully done ||\n");
	printf("		||  DOES NULL SEGF ? ||\n\n");
	i = -1;
	while (++i <= 4)
	{
		list = NULL;
		under_main(list, i);
	}
	printf("\n		|| Successfully done ||\n");
	printf("		||  With 1 element ? ||\n\n");
	i = -1;
	while (++i <= 4)
	{
		list = ft_lstnew(str[1]);
		under_main(list, i);
		if (i != 3)
			print_lst(list);
	}
	printf("\t\t|| Successfully done ALL my tests ||\n");
	printf("\t\t||           Congrats !           ||\n");
	return (0);
}
