
click here to view code ^^

```

#define min(a, b) (a < b ? a : b)

int newArea(int height, int topHeight, int leftHeight)
{
  if(height <= 0) return 0;

  return height * 6 - 2 * ( (height - 1) + min(height, topHeight) + min(height, leftHeight) );
}

int surfaceArea(int** grid, int gridSize, int* gridColSize){

  int **dp = calloc(gridSize + 1, sizeof(int *));

  for(int i = 0; i < gridSize + 1; i++)
  {
    dp[i] = calloc(*gridColSize + 1, sizeof(int));
    memset(dp[i], 0, (*gridColSize + 1) * sizeof(int));
  }

  for(int dpRow = 1; dpRow < gridSize + 1; dpRow++)
  {
    for(int dpCol = 1; dpCol < *gridColSize + 1; dpCol++)
    {
      int gridRow = dpRow - 1;
      int gridCol = dpCol - 1;
      int height = grid[gridRow][gridCol];
      int topHeight = (gridRow - 1) < 0 ? 0 : grid[gridRow - 1][gridCol];
      int leftHeight = (gridCol - 1) < 0 ? 0 : grid[gridRow][gridCol - 1];

      // dp[i][j] = newArea[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
      dp[dpRow][dpCol] =  newArea(height, topHeight, leftHeight) + 
                          dp[dpRow - 1][dpCol] +
                          dp[dpRow][dpCol - 1] -
                          dp[dpRow - 1][dpCol - 1];
    }
  }

  int ret = dp[gridSize][*gridColSize];

  // free dp
  for(int i = 0; i < gridSize + 1; i++)
    free(dp[i]);

  free(dp);

  return ret;
}

```
