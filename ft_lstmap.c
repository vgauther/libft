/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:35:45 by vgauther          #+#    #+#             */
/*   Updated: 2017/11/12 18:59:42 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *new2;

	if (lst && f)
	{
		new2 = f(lst);
		new = f(lst);
		new2 = new;
		if (new2 == NULL)
			return (NULL);
		while (lst->next)
		{
			lst = lst->next;
			new->next = f(lst);
			if (new->next == NULL)
				return (NULL);
			new = new->next;
		}
		return (new2);
	}
	return (NULL);
}
