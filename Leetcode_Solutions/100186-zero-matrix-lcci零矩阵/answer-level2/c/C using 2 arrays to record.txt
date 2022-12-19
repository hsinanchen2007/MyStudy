```
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
  
  // create maps to record rows and cols need to be clear
  char *rowMap = malloc(matrixSize);
  memset(rowMap, 0, matrixSize);
  char *colMap = malloc(*matrixColSize);
  memset(colMap, 0, *matrixColSize);
  
  // fill the map
  for(int row = 0; row < matrixSize; row++)
  {
    for(int col = 0; col < *matrixColSize; col++)
    {
      if(matrix[row][col] == 0)
      {
        rowMap[row] = 1;
        colMap[col] = 1;
      }
    }
  }
  
  // clear rows with rowMap
  for(int i = 0; i < matrixSize; i++)
  {
    if(rowMap[i])
      memset(matrix[i], 0, sizeof(int) * (*matrixColSize));
  }
  
  // clear cols with colMap
  for(int col = 0; col < *matrixColSize; col++)
  {
    if(colMap[col])
    {
      for(int row = 0; row < matrixSize; row++)
        matrix[row][col] = 0;
    }
  }
  
  free(rowMap);
  free(colMap);
}
```
