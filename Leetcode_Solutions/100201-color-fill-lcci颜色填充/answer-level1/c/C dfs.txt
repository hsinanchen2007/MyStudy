```

void dfs(int** image, int rowSize, int colSize, int row, int col, int oldColor, int newColor)
{
  if(row < 0 || row >= rowSize || col < 0 || col >= colSize || image[row][col] != oldColor) return;

  image[row][col] = newColor;

  const int around[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  for(int i = 0; i < 4; i++)
    dfs(image, rowSize, colSize, row + around[i][0], col + around[i][1], oldColor, newColor);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){

  *returnSize = imageSize;
  *returnColumnSizes = imageColSize;

  if(image[sr][sc] != newColor) // in case of dead recursion
    dfs(image, imageSize, *imageColSize, sr, sc, image[sr][sc], newColor);

  return image;
}
```
