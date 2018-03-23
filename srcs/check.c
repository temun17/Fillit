/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnunez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 20:16:37 by pnunez            #+#    #+#             */
/*   Updated: 2018/03/21 10:25:59 by pnunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

int		ft_check_link(char *str, int j)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (i + j < 20 + j)
	{
		if (str[i + j] == '#')
		{
			if ((i + j + 1) < (20 + j) && str[i + j + 1] == '#')
				count++;
			if ((i + j - 1) >= (0 + j) && str[i + j - 1] == '#')
				count++;
			if ((i + j + 5) < (20 + j) && str[i + j + 5] == '#')
				count++;
			if ((i + j - 5) >= (0 + j) && str[i + j - 5] == '#')
				count++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

int		ft_check_game(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i + j] != '\0')
	{
		if (!(ft_validblock(str) && ft_check_link(str, j)))
			return (0);
		i = 19;
		if (str[i + j] == '\n' && str[i + j + 1] == '\0')
			return (1);
		if (str[i + j] == '\n' && str[i + j + 1] == '\n'
				&& (str[i + j + 2] == '.' || str[i + j + 2] == '#'))
			j += 21;
		else
			return (0);
		i = 0;
	}
	return (1);
}

int		ft_validblock(char *str)
{
	static int i = 0;
	static int d = 0;
	static int ln = 0;
	static int h = 0;

	while (str[i] == '.' || str[i] == '#' || str[i] == '\n')
	{
		if (str[i] == '.' || str[i] == '#')
			d++;
		if (str[i] == '#')
			h++;
		if (str[i] == '\n')
			ln++;
		if ((i + 1) % 21 == 0)
			if (str[i] != '\n')
				return (0);
		i++;
	}
	if (d % 16 != 0)
		return (0);
	if (h % 4 != 0 || h == 0)
		return (0);
	if ((ln + 1) % 5 != 0)
		return (0);
	return (((i + 1) % 21 != 0) ? 0 : 1);
}

int		ft_check_block(char **map, t_block *block, int size)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (block->y[i] < size && block->x[i] < size &&
					map[block->y[i]][block->x[i]] == '.')
			{
				i++;
				if (i == 4)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
