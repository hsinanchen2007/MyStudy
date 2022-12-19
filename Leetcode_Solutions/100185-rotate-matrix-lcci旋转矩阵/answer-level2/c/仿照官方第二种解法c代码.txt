

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    for (int x = 0; x < matrixSize; x ++){
      for (int y = x; (y < matrixSize - x -1) && (2 * x < matrixSize - 1); y ++){

         int temp = matrix[matrixSize - y -1][x];
         matrix[matrixSize - y -1][x] = matrix[matrixSize - x - 1][matrixSize - y -1];
         matrix[matrixSize - x - 1][matrixSize - y -1] = matrix[y][matrixSize - x -1];
         matrix[y][matrixSize - x -1] =  matrix[x][y];
         matrix[x][y] = temp;

      }
   }
}

