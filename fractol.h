/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imran <imran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:13:42 by imran             #+#    #+#             */
/*   Updated: 2022/03/19 19:20:48 by imran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//Key codes
#define KEY_ESC 53
#define ARROW_LF 123
#define ARROW_RT 124
#define ARROW_DN 125
#define ARROW_UP 126
#define KEY_R 15
#define KEY_MINUS 27
#define KEY_PLUS 24
#define KEY_1 18
#define KEY_2 19
#define KEY_3 20
#define KEY_4 21
#define KEY_5 23
#define KEY_6 22
#define KEY_7 26
#define KEY_8 28
#define KEY_9 25

//Mouse codes
#define SCROLL_UP 4
#define SCROLL_DN 5

//formula
#define isdigit(c) (c >= '0' && c <= '9')
#define bounded(x, y, i) (x*x+y*y <= 4 && i < fract->max)

//Window dimensions
#define	WIDTH 900
#define HEIGHT 700

//Colors
#define WHITE 0xFFFFFF
#define GREY 0x808080
#define PURPLE 0x800080
#define BLUE 0xFF
#define GREEN 0x006400
#define YELLOW 0xFFFF00
#define BROWN 0x964B00
#define PINK 0xFFC0CB
#define RED 0xFF0000
#define ORANGE 0xFFA500
#define BLK 0x00


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "mlx.h"

typedef struct s_fract
{
	double	scale;
	double	moveX;
	double	moveY;
	double	re_const;
	double	im_const;
	int		max;
	char	type;
	int		color;
}	t_fract;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	t_fract	fract;
}	t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_vars;

void 	fract(t_img *img);
int		key(int keycode, t_vars *data);
int 	mouse(int button, int x, int y, t_vars *data);
void	img_pixel_put(t_img *img, int x, int y, int color);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
double 	ft_atof(const char *s);

#endif