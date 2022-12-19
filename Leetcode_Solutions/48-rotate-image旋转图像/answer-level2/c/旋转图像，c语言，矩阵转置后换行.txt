### 解题思路
转置，换列

### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    for(int i=0;i<matrixSize;i++){
        for(int j=i+1;j<matrixSize;j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    for(int i=0;i<matrixSize/2;i++){
        for(int j=0;j<matrixSize;j++){
            int temp = matrix[j][i];
            matrix[j][i] = matrix[j][matrixSize-1-i];
            matrix[j][matrixSize-1-i] = temp;
        }
    }
}
```