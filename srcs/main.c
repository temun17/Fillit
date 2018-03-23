/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnunez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:16:56 by pnunez            #+#    #+#             */
/*   Updated: 2018/03/21 10:26:10 by pnunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

int		main(int argc, char **argv)
{
	char		*string;
	t_block		*block;

	if (argc != 2)
	{
		ft_putstr("usage [map]");
		return (0);
	}
	string = ft_readstring(argv[1]);
	if (!(ft_check_game(string)))
	{
		ft_putstr("error");
		exit(0);
	}
	block = ft_stock_block(string);
	ft_solve(block);
	return (0);
}
