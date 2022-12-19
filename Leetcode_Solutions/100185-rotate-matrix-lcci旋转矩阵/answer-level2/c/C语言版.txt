### 解题思路
此处撰写解题思路

### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i,j;
    int temp;
    for(i = 1;i < matrixSize;i++){
        for(j = 0;j < i;j++){
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    for(i = 0;i < matrixSize;i++){
        for(j = 0;j < matrixSize / 2;j++){
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize-j-1];
            matrix[i][matrixSize-j-1] = temp;
        }
    }
    return matrix;
}
```