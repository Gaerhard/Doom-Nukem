/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ceiling_height_input_box.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:07:56 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 16:07:58 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		check_ceiling_height_input_box(void *penv)
{
	t_env		*env;
	t_sector	*sector;
	double		prec;

	env = (t_env*)penv;
	if (env->editor.selected_sector != -1)
		sector = &env->sectors[env->editor.selected_sector];
	else
		sector = &env->sectors[env->selected_ceiling];
	prec = sector->ceiling;
	sector->ceiling = ft_atof(env->input_box.str);
	update_sector_slope(env, sector);
	if (sector->floor_max > sector->ceiling_min
		|| check_entities_height(env))
	{
		sector->ceiling = prec;
		update_sector_slope(env, sector);
		update_player_z(env);
		update_start_player_z(env);
		update_sector_enemies_z(env, sector->num);
		return (1);
	}
	return (0);
}
