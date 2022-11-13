/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cntl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imustafa <imustafa@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:20:52 by imran             #+#    #+#             */
/*   Updated: 2022/11/13 10:31:35 by imustafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void set_color(int keycode, t_fract *fract)
{
	if (keycode == KEY_1)
		fract->color = GREY;
	if (keycode == KEY_2)
		fract->color = PURPLE;
	if (keycode == KEY_3)
		fract->color = BLUE;
	if (keycode == KEY_4)
		fract->color = WHITE;
	if (keycode == KEY_5)
		fract->color = YELLOW;
	if (keycode == KEY_6)
		fract->color = BROWN;
	if (keycode == KEY_7)
		fract->color = PINK;
	if (keycode == KEY_8)
		fract->color = RED;
	if (keycode == KEY_9)
		fract->color = ORANGE;
}

void move_image(int keycode, t_fract *fract)
{
	if (keycode == ARROW_LF)
		fract->moveX+=0.5 * 1/fract->scale;
	if (keycode == ARROW_RT)
		fract->moveX-=0.5 * 1/fract->scale;
	if (keycode == ARROW_UP)
		fract->moveY+=0.5 * 1/fract->scale;
	if (keycode == ARROW_DN)
		fract->moveY-=0.5 * 1/fract->scale;
}

void change_iter(int keycode, t_fract *fract)
{
	if (keycode == KEY_MINUS)
	{
		if (fract->max > 100)
			fract->max/= 2;
	}
	if (keycode == KEY_PLUS)
	{
		if (fract->max < 1000)
			fract->max*= 2;
	}
}

int	key(int keycode, t_vars *data)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
	}
	if (keycode == KEY_R)
	{
		data->img.fract.scale = 1.0;
		data->img.fract.moveX = 0.0;
		data->img.fract.moveY = 0.0;
		data->img.fract.max = 400;
		data->img.fract.color = GREEN;
	}
	move_image(keycode, &data->img.fract);
	change_iter(keycode, &data->img.fract);
	set_color(keycode, &data->img.fract);
	return (0);
}

int mouse(int button, int x, int y, t_vars *data)
{
	if (button == SCROLL_DN)
	{
		data->img.fract.moveX-=((x - WIDTH/2.0)*4.0/WIDTH) * 1/data->img.fract.scale;
		data->img.fract.moveY-=((y - HEIGHT/2.0)*4.0/WIDTH)* 1/data->img.fract.scale;
		data->img.fract.scale -= data->img.fract.scale * 0.5;
	}
	if (button == SCROLL_UP)
	{
		data->img.fract.moveX+=((x - WIDTH/2.0)*4.0/WIDTH) * 1/data->img.fract.scale;
		data->img.fract.moveY+=((y - HEIGHT/2.0)*4.0/WIDTH)* 1/data->img.fract.scale;
		data->img.fract.scale += data->img.fract.scale * 0.5;
	}
	return (0);
}