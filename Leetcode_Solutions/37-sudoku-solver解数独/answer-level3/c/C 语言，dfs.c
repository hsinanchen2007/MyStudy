意外地，似乎比较慢。
![图片.png](https://pic.leetcode-cn.com/7c1d560dcd4eac1b5a740bef5938e1b94519430e522a50ed9c3ba4df30dbc021-%E5%9B%BE%E7%89%87.png)

提交版本：
```
void
set( int i, int j, int **row, int **col, int **square, char c )
{
	int num = c - '0';
	int tmp = ( i / 3 ) * 3 + j / 3;

	row[ i ][ num ]++;
	col[ j ][ num ]++;
	square[ tmp ][ num ]++;
}

void
reset( int i, int j, int **row, int **col, int **square, char c )
{
	int num = c - '0';
	int tmp = ( i / 3 ) * 3 + j / 3;

	row[ i ][ num ]--;
	col[ j ][ num ]--;
	square[ tmp ][ num ]--;
}

int
check( int i, int j, int **row, int **col, int **square, char c )
{
	int num = c - '0';
	int tmp = ( i / 3 ) * 3 + j / 3;

	if ( row[ i ][ num ] + 1 > 1 )
		return 0;
	if ( col[ j ][ num ] + 1 > 1 )
		return 0;
	if ( square[ tmp ][ num ] + 1 > 1 )
		return 0;


	return 1;
}

int 
recursion( int i, int j, int **row, int **col, int **square, char **board )
{
	int k = 0, flag = 0; 
	char num = 0;

	if ( !( i == 9 && j == 0 ) )
	{
		if ( board[ i ][ j ] == '.' )
		{
			for ( k = 1; k < 10 && flag == 0; k++ )
			{
				num = ( char )k + '0';
				if ( check( i, j, row, col, square, 
							num ) == 1 )
				{
					set( i, j, row, col, square, num );
					board[ i ][ j ] = num;

					if ( j < 8 )
						flag = recursion( i, j + 1, row, col, 
								square, board );
					else
						flag = recursion( i + 1, 0, row, col, 
								square, board );

					if ( flag == 0 )
					{
						reset( i, j, row, col, square, num );
						board[ i ][ j ] = '.';
					}
				}
			}
		}
		else
		{
			if ( j < 8 )
				flag = recursion( i, j + 1, row, col, square, board );
			else
				flag = recursion( i + 1, 0, row, col, square, board );
		}
	}
	else
		return 1;

	if ( flag == 1 )
		return 1;
	return 0;
}

void
solveSudoku( char **board, int boardSize, int *boardColSize )
{
	int **row = NULL, **col = NULL, **square = NULL;
	int i = 0, j = 0; 

	row = calloc( 10, sizeof( int * ) );
	col = calloc( 10, sizeof( int * ) );
	square = calloc( 10, sizeof( int * ) );

	for ( i = 0; i < 9; i++ )
	{
		row[ i ] = calloc( 12, sizeof( int ) );
		col[ i ] = calloc( 12, sizeof( int ) );
		square[ i ] = calloc( 12, sizeof( int ) );
	}

	for ( i = 0; i < 9; i++ )
		for ( j = 0; j < 9; j++ )
			if ( board[ i ][ j ] != '.' )
				set( i, j, row, col, square, board[ i ][ j ] );

	recursion( 0, 0, row, col, square, board ); 

}
```
提交版本通过 flag 标志位的传递来停止遍历。


实验版本：
```
#include <stdio.h>
#include <stdlib.h>

void
set( int i, int j, int **row, int **col, int **square, char c )
{
	int num = c - '0';
	int tmp = ( i / 3 ) * 3 + j / 3;

	row[ i ][ num ]++;
	col[ j ][ num ]++;
	square[ tmp ][ num ]++;
}

void
reset( int i, int j, int **row, int **col, int **square, char c )
{
	int num = c - '0';
	int tmp = ( i / 3 ) * 3 + j / 3;

	row[ i ][ num ]--;
	col[ j ][ num ]--;
	square[ tmp ][ num ]--;
}

int
check( int i, int j, int **row, int **col, int **square, char c )
{
	int num = c - '0';
	int tmp = ( i / 3 ) * 3 + j / 3;

	if ( row[ i ][ num ] + 1 > 1 )
		return 0;
	if ( col[ j ][ num ] + 1 > 1 )
		return 0;
	if ( square[ tmp ][ num ] + 1 > 1 )
		return 0;


	return 1;
}

void
recursion( int i, int j, int **row, int **col, int **square, char **board )
{
	int k = 0; 
	char num = 0;

	if ( !( i == 9 && j == 0 ) )
	{
		if ( board[ i ][ j ] == '.' )
		{
			for ( k = 1; k < 10; k++ )
			{
				num = ( char )k + '0';
				if ( check( i, j, row, col, square, 
							num ) == 1 )
				{
					set( i, j, row, col, square, num );
					board[ i ][ j ] = num;


					if ( j < 8 )
						recursion( i, j + 1, row, col, square, board );
					else
						recursion( i + 1, 0, row, col, square, board );

					reset( i, j, row, col, square, num );
					board[ i ][ j ] = '.';
				}
			}
		}
		else
		{
			if ( j < 8 )
				recursion( i, j + 1, row, col, square, board );
			else
				recursion( i + 1, 0, row, col, square, board );
		}
	}
	else
	{
		for ( k = 0; k < 9; k++ )
			printf( "%s\n", board[ k ] );
		printf( "\n" );
	}
}

void
solveSudoku( char **board, int boardSize, int *boardColSize )
{
	int **row = NULL, **col = NULL, **square = NULL;
	int i = 0, j = 0; 

	row = calloc( 10, sizeof( int * ) );
	col = calloc( 10, sizeof( int * ) );
	square = calloc( 10, sizeof( int * ) );

	for ( i = 0; i < 9; i++ )
	{
		row[ i ] = calloc( 12, sizeof( int ) );
		col[ i ] = calloc( 12, sizeof( int ) );
		square[ i ] = calloc( 12, sizeof( int ) );
	}

	for ( i = 0; i < 9; i++ )
		for ( j = 0; j < 9; j++ )
			if ( board[ i ][ j ] != '.' )
				set( i, j, row, col, square, board[ i ][ j ] );

	recursion( 0, 0, row, col, square, board ); 

}

int main( int argc, char *argv[] )
{
	/*
	char b[][ 10 ] = {
		"53..7....",
		"6..195...",
		".98....6.",
		"8...6...3",
		"4..8.3..1",
		"7...2...6",
		".6....28.",
		"...419..5",
		"....8..79"
	};
	*/
	char b[][ 10 ] = {
		"..9748...",
		"7........",
		".2.1.9...",
		"..7...24.",
		".64.1.59.",
		".98...3..",
		"...9.3.2.",
		"........6",
		"...2759.."
	};

	int i = 0;
	char **board = NULL;
	board = calloc( 9, sizeof( char * ) );

	for ( i = 0; i < 9; i++ )
		board[ i ] = b[ i ];

	solveSudoku( board, 9, NULL );
	return 0;
}
```

如果有同学还是不理解的话，可以在下面留言，我尽可能地回答你的疑惑。

