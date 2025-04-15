/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ner-roui <ner-roui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:25:35 by naessgui          #+#    #+#             */
/*   Updated: 2025/04/15 09:14:49 by ner-roui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int ft_strcmp(char *s1, char *s2)
{
    int i = 0;

    while((s1[i] == s2[i]) && s1[i] && s2[i])
        i++;
    return (s1[i]-s2[i]);
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)s1;
	s = (unsigned char *)s2;
	i = 0;
	while ((d[i] || s[i]) && i < n)
	{
		if (d[i] != s[i])
			return (d[i] - s[i]);
		i++;
	}
	return (0);
}

void	f_error(char *msg)
{
	// ft_putendl_fd(msg, 2);
	printf("%s\n",msg);
	exit(1);
}


static double	handl_atoi(char *s)
{
	double	fractional_part;
	double	pow;

	fractional_part = 0;
	pow = 1;
	if ('.' == *s)
		++s;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			f_error("Error");
		else
		{
			pow /= 10;
			fractional_part = fractional_part + (*s++ - 48) * pow;
		}
	}
	return (fractional_part);
}

double	ft_atoi(char *s)
{
	double	result;
	long	integer_part;
	int		sign;

	sign = +1;
	integer_part = 0;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	if ('+' == *s || '-' == *s)
	{
		if ('-' == *s)
			sign = -sign;
		s++;
	}
	if (*s == '\0')
		f_error("ERROR");
	while (*s != '.' && *s)
	{
		if (*s < '0' || *s > '9')
			f_error("Error");
		else
			integer_part = (integer_part * 10) + (*s++ - 48);
	}
	result = handl_atoi(s) + integer_part;
	return ((result * sign));
}
void	init_var(t_fractol *fract)
{
	fract->iteration = 500;
	fract->zoom = 300;
	fract->offset_x = 1.3;
	fract->offset_y = 1.3;
	fract->color = get_rgba(0x05, 0x01, 0x01 , 0xff);
}

int get_rgba(int r, int g, int b, int a)
{
	 return (r << 24 | g << 16 | b << 8 | a);
}
int get_rg_l(int r, int g, int b, t_fractol *fract)
{
	int a = 0xff;
	
	r = ((float)(r) * ((float)fract->i / (fract->iteration / 10)));
	g = ((float)(g) * ((float)fract->i / (fract->iteration / 10)));
	b = ((float)(b) * ((float)fract->i / (fract->iteration / 10)));
	return (r << 24 | g << 16 | b << 8 | a);
}
int get_rg_julia(int r, int g, int b, t_fractol *fract)
{
	int a = 0xff;
	r = ((float)(r) * ((float)fract->j / (fract->iteration / 50)));
	g = ((float)(g) * ((float)fract->j / (fract->iteration / 50)));
	b = ((float)(b) * ((float)fract->j / (fract->iteration / 50)));
	return (r << 24 | g << 16 | b << 8 | a);
}
// int main()
// {
// 	char *str = "		-34.75";
// 	printf("%f\n",ft_atoi(str) );
// 	char *str2 = "		-34";
// 	printf("%d\n",atoi(str2) );
// }