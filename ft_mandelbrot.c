/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naessgui <naessgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:25:21 by naessgui          #+#    #+#             */
/*   Updated: 2025/04/14 13:27:45 by naessgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(t_fractol *fract)
{
	double	tmp;
	int		i;

	fract->Zx = 0;
	fract->Zy = 0;
	fract->Cx = ((fract->x / fract->zoom) - fract->offset_x);
	fract->Cy = ((fract->y / fract->zoom) - fract->offset_y);
	i = 0;
	while (++i < fract->iteration)
	{
		tmp = fract->Zx;
		fract->Zx = (fract->Zx * fract->Zx) - (fract->Zy * fract->Zy)
			+ fract->Cx;
		fract->Zy = 2 * tmp * fract->Zy + fract->Cy;
		if ((fract->Zx * fract->Zx) + (fract->Zy * fract->Zy) > 4)
			break ;
	}
	fract->i = i;
	if (i == fract->iteration)
		mlx_put_pixel(fract->image, fract->x, fract->y, fract->color);
	else
	{
		fract->color_2 = get_rg_l(0x49, 0x2e, 0x5e, fract);
		mlx_put_pixel(fract->image, fract->x, fract->y, fract->color_2);
	}
}
