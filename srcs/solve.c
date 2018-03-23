/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:41:02 by atemunov          #+#    #+#             */
/*   Updated: 2018/03/21 10:26:37 by pnunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

void	ft_xy_block(t_block **block, int x, int y)
{
	int		i;
	int		position_x;
	int		position_y;

	i = 0;
	position_x = 100;
	position_y = 100;
	while (i < 4)
	{
		if ((*block)->x[i] < position_x)
			position_x = (*block)->x[i];
		if ((*block)->y[i] < position_y)
			position_y = (*block)->y[i];
		i++;
	}
	i--;
	while (i >= 0)
	{
		(*block)->x[i] = (*block)->x[i] - position_x + x;
		(*block)->y[i] = (*block)->y[i] - position_y + y;
		i--;
	}
}

char	**ft_algor(char **block_map, t_block *block, int size)
{
	int		x;
	int		y;
	char	**map;

	if (block->next == NULL)
		return (block_map);
	map = NULL;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			ft_xy_block(&block, x, y);
			if (ft_check_block(block_map, block, size))
				map = ft_algor(ft_put_block(block_map, block, size),
						block->next, size);
			if (map)
				return (map);
			block_map = ft_remove_block(block_map, block, size);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_solve(t_block *block)
{
	char	**result;
	char	**block_map;
	int		size;

	size = 2;
	block_map = 0;
	block_map = ft_block_map(block_map, size);
	result = 0;
	while (!(result = ft_algor(block_map, block, size)))
	{
		size++;
		ft_memdel((void **)block_map);
		block_map = ft_block_map(block_map, size);
	}
	ft_display_map(result);
}
