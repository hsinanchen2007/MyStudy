```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int result_idx;

void dfs(int *visit, int *result, int **matrix, int matrixRow, int matrixCol, int i, int j)
{
    if (i < 0 || i >= matrixRow || j < 0 || j >= matrixCol || *(visit + i * matrixCol + j) == 1) {
        return;
    }

    visit[i * matrixCol + j] = 1;
    result[result_idx++] = matrix[i][j];
    dfs(visit, result, matrix, matrixRow, matrixCol, i, j + 1);
    dfs(visit, result, matrix, matrixRow, matrixCol, i + 1, j);
    dfs(visit, result, matrix, matrixRow, matrixCol, i, j - 1);
    dfs(visit, result, matrix, matrixRow, matrixCol, i - 1, j);
}

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int col = matrixColSize[0];
    int row = matrixSize;
    int *visit;
    int *result;

    if (row <= 0 || col <= 0) {
        return NULL;
    }

    visit = malloc(sizeof(int) * row * col);
    result = malloc(sizeof(int) * row * col);
    memset(visit, -1, sizeof(int) * row * col);
    dfs(visit, result, matrix, row, col, 0, 0);
    *returnSize = row * col;

    return result;
}
```
*returnSize赋值小一点，提交就不会报踩内存的错误，但是输出不全。