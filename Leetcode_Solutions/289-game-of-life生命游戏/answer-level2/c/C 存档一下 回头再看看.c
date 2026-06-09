click here

```
int around[8][2] = 
{
  // row col  
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, -1},
    {0, 1},
    {1, -1},
    {1, 0},
    {1, 1},
};

int aliveCells(int** board, int row, int col, int rowSize, int colSize)
{
    int ret = 0;

    for(int i = 0; i < 8; i++)
    {
        int newRow = row + around[i][0];
        int newCol = col + around[i][1];

        if( (newRow >= 0 && newRow < rowSize) &&
            (newCol >= 0 && newCol < colSize) )
        {
            if(board[newRow][newCol] % 2 != 0)
                ret++;
        }
    }

    return ret;
}


void gameOfLife(int** board, int boardSize, int* boardColSize){

    if(boardSize == 0) return;

    int colSize = *boardColSize;

    for(int row = 0; row < boardSize; row++)
    {
        for(int col = 0; col < colSize; col++)
        {
            int aroundLive = aliveCells(board, row, col, boardSize, colSize);

            if(board[row][col] % 2 != 0)
            {
                // alive
                if( (aroundLive < 2) || (aroundLive > 3) )
                {
                    board[row][col] = 3; // 1->0
                }
            }
            else
            {
                // dead
                if(aroundLive == 3)
                {
                    board[row][col] = 2; // 0->1
                }
            }
        }
    }

    for(int row = 0; row < boardSize; row++)
    {
        for(int col = 0; col < colSize; col++)
        {
            if(board[row][col] == 3)
            {
                board[row][col] = 0;
            }
            else if(board[row][col] == 2)
            {
                board[row][col] = 1;
            }
        }
    }
}
```
