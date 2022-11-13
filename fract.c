/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imran <imran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:33:25 by imustafa          #+#    #+#             */
/*   Updated: 2022/03/19 19:38:33 by imran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	bship(double c1, double c2, t_fract *fract)
{
	int	i;
	double	x;
	double	y;
	double	t;
	
	x = 0.0;
	y = 0.0;
	t = 0.0;
	i = 0;
	while (bounded(x, y, i)) 
	{
		t = x*x - y*y + c1 - 0.2;
		y = fabs(2*x*y) + c2 - 0.5;
		x = t;
		i++;
	}
	return (i);
}

int	jul(double c1, double c2, t_fract *fract)
{
	int	i;
	double	x;
	double	y;
	double	t;
	
	x = c1;
	y = c2;
	t = 0.0;
	i = 0;
	while (bounded(x, y, i)) 
	{
		t = x*x - y*y + fract->re_const;
		y = 2*x*y + fract->im_const;
		x = t;
		i++;
	}
	return (i);
}

int	mbrot(double c1, double c2, t_fract *fract)
{
	int	i;
	double	x;
	double	y;
	double	t;
	
	x = 0.0;
	y = 0.0;
	t = 0.0;
	i = 0;
	while (bounded(x, y, i)) 
	{
		t = x*x - y*y + c1 - 0.3;
		y = 2*x*y + c2;
		x = t;
		i++;
	}
	return (i);
}

void draw(int row, int col, t_img *img)
{
	double	c_re;
	double	c_im;
	int		i;

	i = 0;
	c_re = ((col - WIDTH/2.0)*4.0/WIDTH) * (1/(img->fract.scale)) + img->fract.moveX;
	c_im = ((row - HEIGHT/2.0)*4.0/WIDTH) * (1/img->fract.scale) + img->fract.moveY;
	if (img->fract.type == 'm')
		i = mbrot(c_re, c_im, &img->fract);
	if (img->fract.type == 'j')
		i = jul(c_re, c_im, &img->fract);
	if (img->fract.type == 'b')
		i = bship(c_re, c_im, &img->fract);
	if (i < img->fract.max)
		img_pixel_put(img, col, row, img->fract.color * i / (img->fract.max / 20));
	else
		img_pixel_put(img, col, row, BLK);
}

void fract(t_img *img)
{
	int 	row;
	int		col;

	row = 0;
	while (row < HEIGHT)
	{	
		col = 0;
		while (col < WIDTH) 
		{
			draw(row, col, img);
			col++;
		}
		row++;
    }
}