/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 02:06:55 by sabdulla          #+#    #+#             */
/*   Updated: 2022/11/22 02:16:06 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	put_coin(t_maps *map, int i, int j)
{
	mlx_put_image_to_window(map->mlx, map->win,
		map->space, j * 64, i * 64);
	mlx_put_image_to_window(map->mlx, map->win,
		map->coin, j * 64, i * 64);
}

void	put_exit(t_maps *map, int i, int j)
{
	mlx_put_image_to_window(map->mlx, map->win,
		map->space, j * 64, i * 64);
	mlx_put_image_to_window(map->mlx, map->win,
		map->exit, j * 64, i * 64);
}

void	put_player(t_maps *map, int i, int j)
{
	mlx_put_image_to_window(map->mlx, map->win,
		map->space, j * 64, i * 64);
	mlx_put_image_to_window(map->mlx, map->win,
		map->player, j * 64, i * 64);
	map->px = j * 64;
	map->py = i * 64;
}

void	print_map(t_maps *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == '1')
				mlx_put_image_to_window(map->mlx, map->win,
					map->wall_p, j * 64, i * 64);
			else if (map->map[i][j] == '0')
				mlx_put_image_to_window(map->mlx, map->win,
					map->space, j * 64, i * 64);
			else if (map->map[i][j] == 'C')
				put_coin(map, i, j);
			else if (map->map[i][j] == 'E')
				put_exit(map, i, j);
			else if (map->map[i][j] == 'P')
				put_player(map, i, j);
		}
	}
}

void	start_game(t_maps *map)
{
	int	w;
	int	h;

	w = map->w * 64;
	h = map->h * 64;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, w, h, "so_long");
	open_xpm(map);
	print_map(map);
	mlx_hook(map->win, 2, 1L << 0, exit_game, map);
	mlx_loop(map->mlx);
}
