//***************************************************
// Filename: othello.c
//
// Author: Nandigam
//***************************************************

#include "othello.h"

// Displays the board (as SIZE x SIZE grid) on console
void displayBoard(char board[][SIZE])
{
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		printf((i == 0 ? "%5d" : "%3d"), i+1);
	}
	printf("\n");

	for (int i = 0; i < SIZE; i++) {
		printf("%2d", i+1);
		for (int j = 0; j < SIZE; j++) {
			printf("%3c", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// Initializes the board with start configuration of discs (see project specs)
void initializeBoard(char board[][SIZE])
{
	for(int i = 0; i < SIZE; i++)		//set up board with all dashes
	{
		for(int j = 0; j < SIZE; j++)
		{
			board[i][j]='-';
		}
	}
	board[3][3]=BLACK;	//make middle spaces black and white, as shown in project description
	board[3][4]=WHITE;
	board[4][3]=WHITE;
	board[4][4]=BLACK;
}

// Returns true if moving the disc to location row,col is valid; else returns false
bool isValidMove(char board[][SIZE], int row, int col, char disc)
{
	int check = 0, i = 0, j = 0;			//will be used to see if every direction has been checked.
	if(disc == BLACK)		//if blacks turn, make sure move can flip white disc
	{				//need to check every direction
		if(board[col-1][row-1] == WHITE)	//see if valid diagonally up and left
		{
			for(i=row-2,j=col-2;i>-1 && j>-1;i--,j--)
			{
				if(board[j][i] == BLACK)
					return true;
				else if(board[j][i] == WHITE){
				}	//continue
				else
				{
					i=-2;
					check++;
				}
			}
		}
		if(board[col][row-1] == WHITE)		//straight up
		{
			for(int i=row-2;i>-1;i--)
			{
				if(board[col][i] == BLACK)
					return true;
				else if(board[col][i] == WHITE){}
					//continue
				else
				{
					i = -2;
					check++;
				}
			}
		}
		if(board[col+1][row-1] == WHITE)	//diagonally up and right
		{
			for(i=row-2,j=col+2;i>-1 && j<8;i--,j++)
			{
				if(board[j][i] == BLACK)
					return true;
				else if(board[j][i] == WHITE){}
					//continue
				else
				{
					i = -2;
					check++;
				}
			}
		}
		if(board[col-1][row] == WHITE)		//straight left
		{
			for(int j = col-2; j>-1; j--)
			{
				if(board[j][row] == BLACK)
					return true;
				else if(board[col][i] == WHITE){}
					//continue
				else
				{
					check++;
				}
			}
		}
		if(board[col+1][row] == WHITE)		//straight right
		{
			for(int j = col+2; j<8; j++)
			{
				if(board[j][row] == BLACK)
					return true;
				else if(board[j][row] == WHITE){}
					//continue
				else
				{
					check++;
				}
			}
		}
		if(board[col-1][row+1] == WHITE)	//diagonally down and left
		{
			for(i=row+2,j=col-2;i<8 && j>-1;i++,j--)
			{
				if(board[j][i] == BLACK)
					return true;
				else if(board[j][i] == WHITE){}
					//continue
				else
				{
					check++;
				}
			}
		}
		if(board[col][row+1] == WHITE)		//straight down
		{
			for(int i = row+2;i<8;i++)
			{
				if(board[col][i] == BLACK)
					return true;
				else if(board[col][i] == WHITE){}
					//continue
				else
				{
					check++;
				}
			}
		}
		if(board[col+1][row+1] == WHITE)	//diagonally down and right
		{
			for(i=row+2,j=col+2;i<8 && j<8;i++,j++)
			{
				if(board[j][i] == BLACK)
					return true;
				else if(board[j][i] == WHITE){}
					//continue
				else
				{
					check++;
				}
			}
		}
		if(check==0 || check != 0)
			return false;			//weird else statement.
	}


	if(disc == WHITE)		//if whites turn, make sure move can flip black disc
	{				//need to check every direction
		if(board[col-1][row-1] == BLACK)	//see if valid diagonally up and left
		{
			for(i=row-2,j=col-2;i>-1 && j>-1;i--,j--)
			{
				if(board[j][i] == WHITE)
					return true;
				else if(board[j][i] == BLACK){}
					//continue
				else
				{
					check++;
				}
			}
		}
		if(board[col][row-1] == BLACK)		//straight up
		{
			for(int i = row-2; i>-1; i--)
			{
				if(board[col][i] == WHITE)
					return true;
				else if(board[col][i] == BLACK){}
					//continue
				else
				{
					check++;
				}
			}
		}
		if(board[col+1][row-1] == BLACK)	//diagonally up and right
		{
			for(i=row-2,j=col+2;i>-1 && j<8;i--,j++)
			{
				if(board[j][i] == WHITE)
					return true;
				else if(board[j][i] == BLACK){}
					//continue
				else
				{
					check++;
				}
			}
		}
		if(board[col-1][row] == BLACK)		//straight left
		{
			for(int j = col-2; j>-1; j--)
			{
				if(board[j][row] == WHITE)
					return true;
				else if(board[col][i] == BLACK){}
					//continue
				else
				{
					check++;
				}
			}
		}
		if(board[col+1][row] == BLACK)		//straight right
		{
			for(int j = col+2; j<8; j++)
			{
				if(board[j][row] == WHITE)
					return true;
				else if(board[j][row] == BLACK){}
					//continue
				else
				{
					check++;
				}
			}
		}
		if(board[col-1][row+1] == BLACK)	//diagonally down and left
		{
			for(i=row+2,j=col-2;i<8 && j>-1;i++,j--)
			{
				if(board[j][i] == WHITE)
					return true;
				else if(board[j][i] == BLACK){}
					//continue
				else
				{
					check++;
				}
			}
		}
		if(board[col][row+1] == BLACK)		//straight down
		{
			for(int i = row+2;i<8;i++)
			{
				if(board[col][i] == WHITE)
					return true;
				else if(board[col][i] == BLACK){}
					//continue
				else
				{
					check++;
				}
			}
		}
		if(board[col+1][row+1] == BLACK)	//diagonally down and right
		{
			for(i=row+2,j=col+2;i<8 && j<8;i++,j++)
			{
				if(board[j][i] == WHITE)
					return true;
				else if(board[j][i] == BLACK){}
					//continue
				else
				{
					check++;
				}
			}
		}
		if(check==0 || check != 0)
			return false;			//weird else statement.
	}
	return false;	// REPLACE THIS WITH YOUR IMPLEMENTATION
}

// Places the disc at location row,col and flips the opponent discs as needed
void placeDiscAt(char board[][SIZE], int row, int col, char disc)
{
int i = 0, j = 0;	//i and j used in loops to determine if discs need to be flipped
int rLoc, cLoc;			//used in loops later to flip discs
	if(isValidMove(board, row, col, disc))
	{
		board[col][row] = disc;
		
		if(disc == BLACK)		//if blacks move is valid, make move flip white discs
		{				//need to check every direction
			if(board[col-1][row-1] == WHITE)	//see if diagonally up and left need to be flipped
			{
				for(i=row-2,j=col-2;i>-1 && j>-1;i--,j--)	//cycle through spaces diagonally left
				{
					if(board[j][i] == BLACK)
					{
						for(cLoc=j+1, rLoc=i+1;cLoc<=col && rLoc<=row;cLoc++, rLoc++)
						{					//if need to be switched, flip all pieces starting with piece furthest from piece just placed
							board[cLoc][rLoc] = BLACK;
						}
						i = -2;					//stop checking if same color disc as placed color is found. 
					}
					else if(board[j][i] == WHITE){
					}	//continue
					else
					{
						i=-2;	//break the loop if no pieces further in this direction
					}
				}
			}
			if(board[col][row-1] == WHITE)		//straight up
			{
				for(int i=row-2;i>-1;i--)
				{
					if(board[col][i] == BLACK)
					{
						for(rLoc=i+1;rLoc<=row;rLoc++)		//start flipping at piece furthest from piece placed
						{
							board[col][rLoc] = BLACK;
						}
						i = -2;
					}
					else if(board[col][i] == WHITE){}
						//continue
					else
					{
						i = -2;
					}
				}
			}
			if(board[col+1][row-1] == WHITE)	//diagonally up and right
			{
				for(i=row-2,j=col+2;i>-1 && j<8;i--,j++)
				{
					if(board[j][i] == BLACK)
					{
						for(cLoc=j-1, rLoc=i+1;cLoc>=col && rLoc<=row;cLoc--, rLoc++)	//same as above method of flipping
						{
							board[cLoc][rLoc] = BLACK;
						}
						i = -2;
					}
					else if(board[j][i] == WHITE){}
						//continue
					else
					{
						i = -2;
					}
				}
			}
			if(board[col-1][row] == WHITE)		//straight left
			{
				for(int j = col-2; j>-1; j--)
				{
					if(board[j][row] == BLACK)
					{
						for(cLoc=j+1;cLoc<=col;cLoc++)
						{
							board[cLoc][row] = BLACK;
						}
						i = -2;
					}
					else if(board[col][i] == WHITE){}
						//continue
					else
					{
						j=-2;
					}
				}
			}
			if(board[col+1][row] == WHITE)		//straight right
			{
				for(int j = col+2; j<8; j++)
				{
					if(board[j][row] == BLACK)
					{
						for(cLoc=j;cLoc>=col;cLoc--)
						{
							board[cLoc][row] = BLACK;
						}
						j = 8;
					}
					else if(board[j][row] == WHITE){}
						//continue
					else
					{
						j=8;
					}
				}
			}
			if(board[col-1][row+1] == WHITE)	//diagonally down and left
			{
				for(i=row+2,j=col-2;i<8 && j>-1;i++,j--)
				{
					if(board[j][i] == BLACK)
					{
						for(cLoc=j+1, rLoc=i-1;cLoc<=col && rLoc>=row;cLoc++, rLoc--)
						{
							board[cLoc][rLoc] = BLACK;
						}
						i=8;
					}
					else if(board[j][i] == WHITE){}
						//continue
					else
					{
						i=8;
					}
				}
			}
			if(board[col][row+1] == WHITE)		//straight down
			{
				for(int i = row+2;i<8;i++)
				{
					if(board[col][i] == BLACK)
					{
						for(rLoc=i+1;rLoc<=row;rLoc++)
						{
							board[col][rLoc] = BLACK;
						}
						i=8;
					}
					else if(board[col][i] == WHITE){}
						//continue
					else
					{
						i=8;
					}
				}
			}
			if(board[col+1][row+1] == WHITE)	//diagonally down and right
			{
				for(i=row+2,j=col+2;i<8 && j<8;i++,j++)
				{
					if(board[j][i] == BLACK)
					{
						for(cLoc=j-1, rLoc=i-1;cLoc>=col && rLoc>=row;cLoc--, rLoc--)
						{
							board[cLoc][rLoc] = BLACK;
						}
						i=8;
					}
					else if(board[j][i] == WHITE){}
						//continue
					else
					{
						i=8;
					}
				}
			}
		}
		if(disc == WHITE)		//if Whites move is valid, make move flip black discs
		{				//need to check every direction
			if(board[col-1][row-1] == BLACK)	//see if diagonally up and left need to be flipped
			{
				for(i=row-2,j=col-2;i>-1 && j>-1;i--,j--)	//cycle through spaces diagonally left
				{
					if(board[j][i] == WHITE)
					{
						for(cLoc=j+1, rLoc=i+1;cLoc<=col && rLoc<=row;cLoc++, rLoc++)
						{					//if need to be switched, flip all pieces starting with piece furthest from piece just placed
							board[cLoc][rLoc] = WHITE;
						}
						i=-2;
					}
					else if(board[j][i] == BLACK){
					}	//continue
					else
					{
						i=-2;	//break the loop if no pieces further in this direction
					}
				}
			}
			if(board[col][row-1] == BLACK)		//straight up
			{
				for(int i=row-2;i>-1;i--)
				{
					if(board[col][i] == WHITE)
					{
						for(rLoc=i+1;rLoc<=row;rLoc++)		//start flipping at piece furthest from piece placed
						{
							board[col][rLoc] = WHITE;
						}
						i=-2;
					}
					else if(board[col][i] == BLACK){}
						//continue
					else
					{
						i = -2;
					}
				}
			}
			if(board[col+1][row-1] == BLACK)	//diagonally up and right
			{
				for(i=row-2,j=col+2;i>-1 && j<8;i--,j++)
				{
					if(board[j][i] == WHITE)
					{
						for(cLoc=j-1, rLoc=i+1;cLoc>=col && rLoc<=row;cLoc--, rLoc++)	//same as above method of flipping
						{
							board[cLoc][rLoc] = WHITE;
						}
						i=-2;
					}
					else if(board[j][i] == BLACK){}
						//continue
					else
					{
						i = -2;
					}
				}
			}
			if(board[col-1][row] == BLACK)		//straight left
			{
				for(int j = col-2; j>-1; j--)
				{
					if(board[j][row] == WHITE)
					{
						for(cLoc=j+1;cLoc<=col;cLoc++)
						{
							board[cLoc][row] = WHITE;
						}
						j=-2;
					}
					else if(board[col][i] == BLACK){}
						//continue
					else
					{
						j=-2;
					}
				}
			}
			if(board[col+1][row] == BLACK)		//straight right
			{
				for(int j = col+2; j<8; j++)
				{
					if(board[j][row] == WHITE)
					{
						for(cLoc=j-1;cLoc>=col;cLoc--)
						{
							board[cLoc][row] = WHITE;
						}
						j=8;
					}
					else if(board[j][row] == BLACK){}
						//continue
					else
					{
						j=8;
					}
				}
			}
			if(board[col-1][row+1] == BLACK)	//diagonally down and left
			{
				for(i=row+2,j=col-2;i<8 && j>-1;i++,j--)
				{
					if(board[j][i] == WHITE)
					{
						for(cLoc=j+1, rLoc=i-1;cLoc<=col && rLoc>=row;cLoc++, rLoc--)
						{
							board[cLoc][rLoc] = WHITE;
						}
						i=8;
					}
					else if(board[j][i] == BLACK){}
						//continue
					else
					{
						i=8;
					}
				}
			}
			if(board[col][row+1] == BLACK)		//straight down
			{
				for(int i = row+2;i<8;i++)
				{
					if(board[col][i] == WHITE)
					{
						for(rLoc=i+1;rLoc<=row;rLoc++)
						{
							board[col][rLoc] = WHITE;
						}
						i=8;
					}
					else if(board[col][i] == BLACK){}
						//continue
					else
					{
						i=8;
					}
				}
			}
			if(board[col+1][row+1] == BLACK)	//diagonally down and right
			{
				for(i=row+2,j=col+2;i<8 && j<8;i++,j++)
				{
					if(board[j][i] == WHITE)
					{
						for(cLoc=j-1, rLoc=i-1;cLoc>=col && rLoc>=row;cLoc--, rLoc--)
						{
							board[cLoc][rLoc] = WHITE;
						}
						i=8;
					}
					else if(board[j][i] == BLACK){}
						//continue
					else
					{
						i=8;
					}
				}
			}
		}
	}
}

// Returns true if a valid move for disc is available; else returns false
bool isValidMoveAvailable(char board[][SIZE], char disc)
{
	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{
			if(board[i][j] =='-')
			{
				if(isValidMove(board,i,j,disc))
				{
					return true;
				}
			}
		}
	}
	return false;	// REPLACE THIS WITH YOUR IMPLEMENTATION
}

// Returns true if the board is fully occupied with discs; else returns false
bool isBoardFull(char board[][SIZE])
{
	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{
			if(board[i][j] =='-')
			{
				return false;
			}
		}
	}
	return true;	// REPLACE THIS WITH YOUR IMPLEMENTATION	
}

// Returns true if either the board is full or a valid move is not available for either disc
bool isGameOver(char board[][SIZE])
{
	if(isBoardFull(board) || (!isValidMoveAvailable(board, BLACK) && !isValidMoveAvailable(board, WHITE)))
		return true;
	return false;	// REPLACE THIS WITH YOUR IMPLEMENTATION
}

// If there is a winner, it returns the disc (BLACK or WHITE) associated with the winner.
// In case of a tie, it returns EMPTY
char checkWinner(char board[][SIZE])
{
	int black = 0, white = 0;
	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{
			if(board[i][j] == BLACK)
				black++;
			if(board[i][j] == WHITE)
				white++;
		}
	}
	if(black>white)
		return BLACK;
	else if(white>black)
		return WHITE;
	return EMPTY;	// REPLACE THIS WITH YOUR IMPLEMENTATION
}
