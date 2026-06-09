### 解题思路
旋转90度 = 先沿着左对角线对折，然后再进行中间对折
### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int sequal  = matrixSize -1;
    if( matrixSize == 1) {
        return;
    }

    //先沿着对角线反转
    for(int i = 0; i < matrixSize; i++) {
        for(int j = i + 1; j < matrixSize; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    //对折
    for(int j = 0 ; j < matrixSize/2 ; j++) {
        for(int  i = 0; i < matrixSize; i++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize - 1 - j];
            matrix[i][matrixSize - 1 - j] = temp;        
        }
    }
}
```