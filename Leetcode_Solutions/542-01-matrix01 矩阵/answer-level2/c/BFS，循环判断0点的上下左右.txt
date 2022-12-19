### 解题思路
此处撰写解题思路

### 代码
```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define DIR 4
#define MAXLEN 10000

void bfs(int** matrix, int matrixSize, int* matrixColSize, int** buf, int* num, int cir, int* X, int* Y) 
{
    int row[DIR] = {-1, 0, 1, 0};
    int col[DIR] = {0, 1, 0, -1};

    int tmp = *num;
    for (int m = 0; m < tmp; m++) {
        for (int n = 0; n < DIR; n++) {
            if (X[m] + row[n] < 0 || X[m] + row[n] >= matrixSize || Y[m] + col[n] < 0 || Y[m] + col[n] >= matrixColSize[X[m]]) {
                continue;
            }

            if (matrix[X[m] + row[n]][Y[m] + col[n]] == 1) {
                buf[X[m] + row[n]][Y[m] + col[n]] = 1 + cir;
                matrix[X[m] + row[n]][Y[m] + col[n]] = 0;
            }
        }
    }
    
}

int RefreshArr(int** matrix, int matrixSize, int* matrixColSize, int* X, int* Y)
{
    int k = 0;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            if (matrix[i][j] == 0) {
                X[k] = i;
                Y[k] = j;
                k++;
            }        
        }
    }
    return k;
}

int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes)
{
    if (matrix == NULL || matrixSize <= 0) {
        return NULL;
    }

    int X[MAXLEN];
    int Y[MAXLEN];
    int num = 0;
    int ALLnum = 0;

    int** buf =(int **)malloc(sizeof(int *) * matrixSize);
    for (int i = 0; i < matrixSize; i++) {
        buf[i] = (int *)malloc(sizeof(int) * matrixColSize[i]);
        for (int j = 0; j < matrixColSize[i]; j++) {
            buf[i][j] = 0;
            ALLnum++;
        }
    }

    int cir = 0;
    while(num < ALLnum) {
        num = RefreshArr(matrix, matrixSize, matrixColSize, X, Y);
        bfs(matrix, matrixSize, matrixColSize, buf, &num, cir, X, Y);
        cir++; 
    }
 
    *returnSize = matrixSize;
    *returnColumnSizes = (int *)malloc(sizeof(int) * matrixSize);
    for (int p = 0; p < matrixSize; p++) {
        *(*returnColumnSizes + p) = matrixColSize[p];
    }
    
    return buf;
}
```