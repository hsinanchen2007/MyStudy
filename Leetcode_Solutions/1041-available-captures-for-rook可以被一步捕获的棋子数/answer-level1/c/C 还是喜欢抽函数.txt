
clice here to review

```

static const int directions[4][2] = {
  {0, 1},
  {0, -1},
  {1, 0},
  {-1, 0}
};

// tail recursion
bool canCatchAtDir(char** board, int rolSize, int colSize, int row, int col, int dir)
{
  if(row >= 0 && row < rolSize && col >= 0 && col < colSize)
  {
    if(board[row][col] == 'p')      return 1;    
    else if(board[row][col] == 'B') return 0;
    else                            return canCatchAtDir( board, 
                                                          rolSize, colSize, 
                                                          row + directions[dir][0], 
                                                          col + directions[dir][1], 
                                                          dir);
  }
  
  return 0;
}

int numRookCaptures(char** board, int boardSize, int* boardColSize){

  int ret = 0;

  for(int row = 0; row < boardSize; row++)
  {
    for(int col = 0; col < *boardColSize; col++)
    {
      if(board[row][col] == 'R')
      {
        for(int dir = 0; dir < 4; dir++)
          ret += canCatchAtDir(board, boardSize, *boardColSize, row, col, dir);

        break;
      }
    }
  }

  return ret;
}

```
