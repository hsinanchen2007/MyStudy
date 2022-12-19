```

void backTrace(int** obstacleGrid, int rowSize, int colSize, int row, int col, int **ret, int *returnSize, bool *arrived, int depth, bool visited[][100])
{
  if(row >= rowSize || col >= colSize || obstacleGrid[row][col] == 1 || *arrived || visited[row][col]) return;

  // add this grid to ret
  visited[row][col] = 1;
  ret[depth][0] = row;
  ret[depth][1] = col;

  if(row == (rowSize - 1) && col == (colSize - 1)) 
  {
    *arrived = 1;
    *returnSize = depth + 1;
  }
  else
  {
    backTrace(obstacleGrid, rowSize, colSize, row, col + 1, ret, returnSize, arrived, depth + 1, visited); 
    backTrace(obstacleGrid, rowSize, colSize, row + 1, col, ret, returnSize, arrived, depth + 1, visited);
  }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pathWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize, int* returnSize, int** returnColumnSizes){

  *returnSize = 0;

  int **ret = malloc(sizeof(int *) * 200);

  for(int i = 0; i < 200; i++)
    ret[i] = malloc(sizeof(int) * 2);

  bool arrived = 0;

  bool visited[100][100];
  for(int i = 0; i < obstacleGridSize; i++)
    memset(visited[i], 0, sizeof(bool) * (*obstacleGridColSize));

  backTrace(obstacleGrid, obstacleGridSize, *obstacleGridColSize, 0, 0, ret, returnSize, &arrived, 0, visited);

  if(arrived)
  {
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));

    for(int i = 0; i < *returnSize; i++)
      (*returnColumnSizes)[i] = 2;
  }
  else *returnSize = 0;

  return ret;
}

```
