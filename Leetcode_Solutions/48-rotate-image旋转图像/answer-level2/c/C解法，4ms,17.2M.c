**思路**
先以对角为对称轴进行反转，再以y轴进行反转。
```
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    /* 先以对角线为对称轴反转 */
    for (int row = 1; row < matrixSize; row++) {
        for (int col = 0; col < row; col++) {
            swap(&matrix[row][col], &matrix[col][row]);
        }
    }
    
    /* 再以y轴反转 */
    for (int col = 0; col < (*matrixColSize) / 2; col++) {
        for (int row = 0; row < matrixSize; row++) {
            swap(&matrix[row][col], &matrix[row][*matrixColSize - 1 - col]);
        }
    }
}


```
