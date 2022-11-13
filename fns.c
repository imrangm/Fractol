/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fns.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imran <imran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:15:24 by imran             #+#    #+#             */
/*   Updated: 2022/03/19 18:04:48 by imran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;
	int				count;

	i = 0;
	count = 0;
	a = (unsigned char *) s1;
	b = (unsigned char *) s2;
	if (n == 0 || (a == 0 && b == 0))
		return (0);
	while (i < n && (a[i] != '\0' || b[i] != '\0'))
	{
		if (a[i] != b[i])
		{
			count += a[i] - b[i];
			break ;
		}
		i++;
	}
	return (count);
}

double ft_atof(const char *s)
{
  double a;
  int e;
  int c;
  int neg;
  
  a = 0.0;
  e = 0;
  neg = 1;
  if (!s)
	return (0.0);
  if (*s == '-' || *s == '+')
  {
		if (*s++ == '-')
			neg = -1;
  }
  while ((c = *s++) != '\0' && isdigit(c)) 
    a = a*10.0 + (c - '0');
  if (c == '.') 
  {
    while ((c = *s++) != '\0' && isdigit(c)) 
	{
      a = a*10.0 + (c - '0');
      e = e-1;
    }
  }
  while (e < 0) 
  {
    a *= 0.1;
    e++;
  }
  return (a*neg);
}

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(int *)dst = color;
}