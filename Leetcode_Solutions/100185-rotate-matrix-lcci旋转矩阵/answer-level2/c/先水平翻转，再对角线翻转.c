### 解题思路
此处撰写解题思路

### 代码

```c
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    for (int i = 0; i < matrixSize / 2; i++) {
        for (int j = 0; j < matrixSize; j++) {
            swap(&matrix[i][j], &matrix[matrixSize - 1 - i][j]);
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < i; j++) {
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }
}
```