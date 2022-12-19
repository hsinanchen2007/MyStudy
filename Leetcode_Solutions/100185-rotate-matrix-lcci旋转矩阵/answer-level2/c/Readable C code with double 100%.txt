

```
void rotate(int** matrix, int matrixSize, int* matrixColSize){
  
  // rotate the points from outside to inside
  for(int rowStart = 0, colStart = 0; rowStart < (matrixSize + 1) / 2; rowStart++, colStart++)
  {
    for(int col = colStart, row = rowStart; col < matrixSize - 1 - colStart; col++)
    {
      // calculate the locations to be rotated
      int *top  = matrix[row] + col;
      int *bot =  matrix[matrixSize - 1 - row] + matrixSize - 1 - col;
      int *right = matrix[col] + matrixSize - 1 - rowStart;
      int *left = matrix[matrixSize - 1 - col] + rowStart;

      // rotate
      int tmp = *top;
      *top = *left;
      *left = *bot;
      *bot = *right;
      *right = tmp;
    }
  }
  
}
```
