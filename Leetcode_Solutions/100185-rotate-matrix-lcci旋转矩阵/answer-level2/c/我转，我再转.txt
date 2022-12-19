### 解题思路
先垂直，再主对角线旋转

### 代码

```c
void swap(int *a, int *b) {
    if (a == b) {
        return;
    }
    int c = *a;
    *a = *b;
    *b = c;
}


void rotateVertical(int **matrix, int N)
{
    for (int i = 0; i < N; ++i) {
        int l = 0;
        int r = N - 1;
        while (l < r) {
            swap(&matrix[l++][i], &matrix[r--][i]);
        }
    }
};

void rotateDiag(int **matrix, int N)
{
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }
}

void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    if (matrixSize < 2) {
        return;
    }
    rotateVertical(matrix, matrixSize);
    rotateDiag(matrix, matrixSize);
}
```