#include "life.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * get_grid creates new memory for a "grid".
 * x is the height and y is the width.
 */
char** get_grid(int x, int y){
	char** grid = (char**)malloc(x*sizeof(char*));
	for(int i = 0; i < y; i++)
	{
		grid[i] = (char*)malloc(y*sizeof(char));
	}
	return grid;
}

/*
 * print_grid attempts to print an x height
 * by y width grid stored at the location
 * provided by grid
 */
void print_grid(int x, int y, char** grid){
	printf("\n");
	for(int i = 0; i<x; i++)
	{
		for(int j = 0; j < y; j++)
		{
			printf("%d", atoi(&grid[i][j]));
		}
		printf("\n");
	}
}

/*
 * mutate takes a grid and mutates that grid
 * according to Conway's rules.  A new grid
 * is returned.
 */
char** mutate(int x, int y, char** grid){
	for(int i = 0; i < x; i++)
	{
		for(int j = 0; j < y; j++)
		{
			if(grid[i][j] =='1')
			{
				if(get_neighbors(i,j,x,y,grid) == 2 || get_neighbors(i,j,x,y,grid) == 3)
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
	return grid;
}

/* get_neighbors is a helper method that returns
 * the number of live neighbors a cell has.
 */
int get_neighbors(int i, int j, int x, int y, char** grid)
{
	int neighbors = 0;
	if(i>0 && j >0)
	{
		if(grid[i-1][j-1] == '1')	//need to check every direction. Up and left.
		{
			neighbors++;
		}
	}
	if(i>0)
	{
		if(grid[i-1][j] == '1')		//Straight up.
		{
			neighbors++;
		}
	}
	if(i>0 && j < y)
	{
		if(grid[i-1][j+1] == '1')	//Up and Right.
		{
			neighbors++;
		}
	}
	if(j>0)
	{
		if(grid[i][j-1] == '1')		//Straight Left.
		{
			neighbors++;
		}
	}
	if(j<y)
	{	
		if(grid[i][j+1] == '1')		//Straight right.
		{
			neighbors++;
		}
	}
	if(i<x && j>0)
	{
		if(grid[i+1][j-1] == '1')	//Down and Left.
		{
			neighbors++;
		}
	}
	if(i<x)
	{
		if(grid[i+1][j] == '1')		//Straight Down.
		{
			neighbors++;
		}
	}
	if(i<x && j<y)
	{
		if(grid[i+1][j+1] == '1')	//Down and RIght.
		{
			neighbors++;
		}
	}
	return neighbors;
}
