/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:37:21 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:37:22 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	hline(t_env *env, int y)
{
	int x;

	x = 400;
	while (x < env->w)
	{
		env->sdl.texture_pixels[x + y * env->w] = 0xFF888888;
		x++;
	}
}

void	vline(t_env *env, int x)
{
	int y;

	y = 0;
	while (y < env->h)
	{
		env->sdl.texture_pixels[x + y * env->w] = 0xFF888888;
		y++;
	}
}

void	draw_hgrid(t_env *env)
{
	double	i;

	i = env->editor.center.y;
	while (i < 0)
		i += env->editor.scale;
	while (i < env->h)
	{
		hline(env, i);
		i += env->editor.scale;
	}
	i = env->editor.center.y - env->editor.scale;
	while (i >= env->h)
		i -= env->editor.scale;
	while (i >= 0)
	{
		hline(env, i);
		i -= env->editor.scale;
	}
}

void	draw_vgrid(t_env *env)
{
	double	i;

	i = env->editor.center.x;
	while (i < 400)
		i += env->editor.scale;
	while (i < env->w)
	{
		vline(env, i);
		i += env->editor.scale;
	}
	i = env->editor.center.x - env->editor.scale;
	while (i >= env->w)
		i -= env->editor.scale;
	while (i >= 400)
	{
		vline(env, i);
		i -= env->editor.scale;
	}
}
