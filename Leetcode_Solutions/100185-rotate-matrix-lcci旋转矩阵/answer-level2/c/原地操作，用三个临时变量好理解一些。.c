### 解题思路
首先确定要转几圈，从外圈到内圈来处理。

### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int cycle = matrixSize / 2;   
    
    for (int c = 0; c < cycle; c++) {
        for (int i = c; i < matrixSize - c - 1; i++) {
            int a1 = matrix[i][matrixSize - 1 - c];
            matrix[i][matrixSize - 1 - c] = matrix[c][i];

            int a2 =  matrix[matrixSize - 1 - c][matrixSize - 1 - i];
            matrix[matrixSize - 1 - c][matrixSize - 1 - i] = a1;

            int a3 = matrix[matrixSize - 1 - i][c];
            matrix[matrixSize - 1 - i][c] = a2;

            matrix[c][i] = a3;
        }
    }

}
```