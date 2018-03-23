/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnunez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 20:15:15 by pnunez            #+#    #+#             */
/*   Updated: 2018/03/21 10:26:27 by pnunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"
#include <fcntl.h>

int			ft_count_block(char *str)
{
	int		i;
	int		result;

	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			result++;
		i++;
	}
	return (result / 4);
}

void		ft_set_block(t_block **tmp, char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			(*tmp)->x[j] = i % 5;
			(*tmp)->y[j] = i / 5;
			j++;
		}
		i++;
	}
}

t_block		*ft_stock_block(char *str)
{
	int		c_block;
	int		add21;
	char	letter;
	t_block *stock;
	t_block *tmp;

	add21 = 0;
	letter = 'A';
	c_block = ft_count_block(str);
	if (!(stock = (t_block *)malloc(sizeof(t_block))))
		return (NULL);
	tmp = stock;
	while (c_block > 0)
	{
		tmp->c = letter;
		ft_set_block(&tmp, ft_strsub(str, 0 + add21, 20));
		if (!(tmp->next = (t_block *)malloc(sizeof(t_block))))
			return (NULL);
		tmp = tmp->next;
		c_block--;
		letter++;
		add21 += 21;
	}
	tmp->next = NULL;
	return (stock);
}

char		*ft_readstring(char *str)
{
	size_t	i;
	int		fd;
	char	buf;
	char	*strr;

	i = 0;
	fd = open(str, O_RDONLY);
	while (read(fd, &buf, 1))
		i++;
	if (i >= 546 || i < 20)
	{
		ft_putstr("error");
		exit(0);
	}
	strr = ft_strnew(i);
	i = 0;
	close(fd);
	fd = open(str, O_RDONLY);
	while (read(fd, &buf, 1))
		strr[i++] = buf;
	close(fd);
	return (strr);
}
