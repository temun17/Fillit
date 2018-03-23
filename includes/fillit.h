/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemunov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 19:32:48 by atemunov          #+#    #+#             */
/*   Updated: 2018/03/21 10:26:50 by pnunez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct		s_block
{
	char			c;
	int				x[4];
	int				y[4];
	struct s_block	*next;
}					t_block;

void				ft_xy_block(t_block **block, int x, int y);
char				**ft_algor(char **block_map, t_block *block, int size);
void				ft_solve(t_block *block);
int					ft_count_block(char *str);
void				ft_set_block(t_block **tmp, char *str);
t_block				*ft_stock_block(char *str);
char				*ft_readstring(char *str);
char				**ft_block_map(char **map, int size);
void				ft_display_map(char **map);
char				**ft_remove_block(char **map, t_block *block, int size);
char				**ft_put_block(char **map, t_block *block, int size);
int					ft_check_link(char *str, int j);
int					ft_check_block(char **map, t_block *block, int size);
int					ft_validblock(char *str);
int					ft_check_game(char *str);

#endif
