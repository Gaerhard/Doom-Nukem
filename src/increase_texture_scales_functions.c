/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_texture_scales_functions.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:06:29 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/30 11:44:15 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		increase_ceiling_texture_scale(t_env *env)
{
	t_sector *sector;

	sector = &env->sectors[env->selected_ceiling];
	if (check_texture_scale(env, &sector->ceiling_map_scale))
	{
		if (env->inputs.shift && !env->inputs.ctrl)
		{
			sector->ceiling_map_scale.y *= 1.1;
			sector->ceiling_map_scale.x *= 1.1;
		}
		else if (env->inputs.ctrl)
			sector->ceiling_map_scale.y *= 1.1;
		else
			sector->ceiling_map_scale.x *= 1.1;
		if (set_sector_ceiling_map_array(sector,
		&env->wall_textures[sector->ceiling_texture], env))
			return (-1);
	}
	return (0);
}

int		increase_floor_texture_scale(t_env *env)
{
	t_sector *sector;

	sector = &env->sectors[env->selected_floor];
	if (check_texture_scale(env, &sector->floor_map_scale))
	{
		if (env->inputs.shift && !env->inputs.ctrl)
		{
			sector->floor_map_scale.y *= 1.1;
			sector->floor_map_scale.x *= 1.1;
		}
		else if (env->inputs.ctrl)
			sector->floor_map_scale.y *= 1.1;
		else
			sector->floor_map_scale.x *= 1.1;
		if (set_sector_floor_map_array(sector,
		&env->wall_textures[sector->floor_texture],
		env))
			return (-1);
	}
	return (0);
}

int		increase_wall_texture_scale(t_env *env)
{
	t_sector *sector;

	sector = &env->sectors[env->editor.selected_sector];
	if (check_texture_scale(env, &sector->scale[env->editor.selected_wall]))
	{
		if (env->inputs.shift && !env->inputs.ctrl)
		{
			sector->scale[env->editor.selected_wall].y *= 1.1;
			sector->scale[env->editor.selected_wall].x *= 1.1;
		}
		else if (env->inputs.ctrl)
			sector->scale[env->editor.selected_wall].y *= 1.1;
		else
			sector->scale[env->editor.selected_wall].x *= 1.1;
		if (set_sector_wall_map_array(sector,
		&env->wall_textures[sector->textures[env->editor.selected_wall]],
		env->editor.selected_wall, env))
			return (-1);
		if (set_camera_map_array(&env->player.camera,
		env->editor.selected_sector, env->editor.selected_wall, env))
			return (-1);
	}
	return (0);
}
