#include "life.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * get_grid creates new memory for a "grid".
 * x is the height and y is the width.
 */
char** get_grid(int x, int y){
	printf("inside here1");
	char** grid = (char**)malloc(x*sizeof(char*));
	for(int i = 0; i < y; i++)
	{
		grid[i] = (char*)malloc(y*sizeof(char));
	}
	printf("inside here2");
	return grid;
}

/*
 * print_grid attempts to print an x height
 * by y width grid stored at the location
 * provided by grid
 */
void print_grid(int x, int y, char** grid){
	printf("inside here3");
	for(int i = 0; i<x; i++)
	{
		for(int j = 0; j < y; j++)
		{
			printf("%c", grid[i][j]);
		}
	}
}

/*
 * mutate takes a grid and mutates that grid
 * according to Conway's rules.  A new grid
 * is returned.
 */
char** mutate(int x, int y, char** grid){
	printf("inside here4");
	for(int i = 0; i < x; i++)
	{
		for(int j = 0; j < y; j++)
		{
			if(grid[i][j] =='1')
			{
				if(get_neighbors(i,j,x,y,grid) < 2)
				{
					grid[i][j] = '0';
				}
				else if(get_neighbors(i,j,x,y,grid) == 2 || get_neighbors(i,j,x,y,grid) == 3)
				{
					grid[i][j] = '1';
				}
				else
				{
					grid[i][j] = '0';
				}
			}
			else
			{
				if(get_neighbors(i,j,x,y,grid) == 3)
				{
					grid[i][j] = '1';
				}
			}
		}
	}
	printf("inside here5");
	return grid;
}

/* get_neighbors is a helper method that returns
 * the number of live neighbors a cell has.
 */
int get_neighbors(int i, int j, int x, int y, char** grid)
{
	printf("inside here6");
	int neighbors = 0;
	if(grid[x-1][y-1] == '1')	//need to check every direction. Up and left.
	{
		neighbors++;
	}
	if(grid[x-1][y] == '1')		//Straight up.
	{
		neighbors++;
	}
	if(grid[x-1][y+1] == '1')	//Up and Right.
	{
		neighbors++;
	}
	if(grid[x][y-1] == '1')		//Straight Left.
	{
		neighbors++;
	}	
	if(grid[x][y+1] == '1')		//Straight right.
	{
		neighbors++;
	}
	if(grid[x+1][y-1] == '1')	//Down and Left.
	{
		neighbors++;
	}
	if(grid[x+1][y] == '1')		//Straight Down.
	{
		neighbors++;
	}
	if(grid[x+1][y+1] == '1')	//Down and RIght.
	{
		neighbors++;
	}
	return neighbors;
}
