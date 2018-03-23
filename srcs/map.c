/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:33:05 by atemunov          #+#    #+#             */
/*   Updated: 2018/03/21 10:26:18 by pnunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fillit.h"

char	**ft_block_map(char **map, int size)
{
	int pos_x;
	int pos_y;

	pos_y = 0;
	if (!(map = (char **)malloc(sizeof(char *) * size + 1)))
		return (0);
	while (pos_y < size)
	{
		if (!(map[pos_y] = (char *)malloc(sizeof(char) * size + 1)))
			return (0);
		pos_x = 0;
		while (pos_x < size)
		{
			map[pos_y][pos_x] = '.';
			pos_x++;
		}
		map[pos_y][pos_x] = '\0';
		pos_y++;
	}
	map[pos_y] = 0;
	return (map);
}

void	ft_display_map(char **map)
{
	int	i;

	if (map == NULL)
	{
		ft_putendl("error\n");
		return ;
	}
	i = 0;
	while (map[i] != '\0')
	{
		ft_putendl(map[i]);
		i++;
	}
}

char	**ft_remove_block(char **map, t_block *block, int size)
{
	int pos_x;
	int pos_y;

	pos_y = 0;
	while (pos_y < size)
	{
		pos_x = 0;
		while (pos_x < size)
		{
			if (map[pos_y][pos_x] == block->c)
				map[pos_y][pos_x] = '.';
			pos_x++;
		}
		pos_y++;
	}
	return (map);
}

char	**ft_put_block(char **map, t_block *block, int size)
{
	int	pos_x;
	int pos_y;
	int index;

	index = 0;
	pos_y = 0;
	while (pos_y < size)
	{
		pos_x = 0;
		while (pos_x < size)
		{
			if (block->y[index] == pos_y && block->x[index] == pos_x)
			{
				map[pos_y][pos_x] = block->c;
				index++;
			}
			pos_x++;
		}
		pos_y++;
	}
	return (map);
}
