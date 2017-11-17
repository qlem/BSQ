/*
** my.h for BSQ in /home/dommer_c/rendu/CPE_2015_BSQ/include
** 
** Made by clement dommerc
** Login   <dommer_c@epitech.net>
** 
** Started on  Mon Dec 14 18:06:03 2015 clement dommerc
** Last update Sun Dec 20 18:23:48 2015 clement dommerc
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct s_dim
{
  int	line;
  int	col;
  int	x;
  int	y;
  int	size;
  int	pl;
}t_dim;

int	    open_map(char *file, char **map);
void	dim_tab(char *map, t_dim *dim);
t_dim	*mem_dim(t_dim *dim);
char	*mem_map(char *map, int size);
int	    **mem_tab(int **tab, t_dim *dim);
void	free_mem(char *map, t_dim *dim, int **tab);
int	    **create_tab(char*map, t_dim *dim);
void	tab_set(int **tab, t_dim *dim, char *map);
int	    search_min(int **tab, int i, int j);
void	search_square(int **tab, t_dim *dim, int i, int j);
void	display_bsq(t_dim *dim, char *map);
void	display_tab(int **tab, t_dim *dim);

#endif
