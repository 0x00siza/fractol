/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naessgui <naessgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:36:43 by naessgui          #+#    #+#             */
/*   Updated: 2025/04/14 13:41:08 by naessgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_fractol *fract)
{
	double tmp;
	int color;
	fract->Zx = ((fract->x / fract->zoom) - fract->offset_x);
	fract->Zy = ((fract->y / fract->zoom) - fract->offset_y);
	int i;
	
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
	fract->j = i;
	if (i == fract->iteration)  
		mlx_put_pixel(fract->image, fract->x, fract->y,fract->color);

	else
	{
		color = get_rg_julia(0x49, 0x2e, 0x5e,fract);
		mlx_put_pixel(fract->image, fract->x, fract->y, color);
	}
}

		// uint8_t r = (0x05);                       
		// uint8_t g = (0x01);
		// uint8_t b = (0x01);
		// uint8_t r = ((float)(0x72) * ((float)i / (fract->iteration / 10)));
		// uint8_t g = ((float)(0xb5) * ((float)i / (fract->iteration / 10)));
		// uint8_t b = ((float)(0x48) * ((float)i / (fract->iteration / 10)));