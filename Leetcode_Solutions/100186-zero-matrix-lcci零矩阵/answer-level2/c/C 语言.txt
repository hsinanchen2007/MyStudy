### 解题思路
此处撰写解题思路

（1）申请一个数组arr初始化值全为1，遍历matrix并将数组中0元素的位置在arr上相应的位置上置0,；
（2）遍历arr，将arr中位置为0且相应的matrix行和列中的元素置为0即可。

### 代码

```c
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int row, col, i, j, m;
    int **arr = NULL;

    if (matrix == NULL || matrixSize <= 0) {
        return;
    }

    row = matrixSize;
    col = *matrixColSize;
    arr = (int **)malloc(sizeof(int *) * row);
    for (i = 0; i < row; i++) {
        arr[i] = (int *)malloc(sizeof(int) * col);
        memset(arr[i], 1, sizeof(int) * col);
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (matrix[i][j] == 0) {
                arr[i][j] = 0;
            }
        }
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (arr[i][j] == 0) {
                for (m = 0; m < row; m++) {
                    matrix[m][j] = 0;
                }
                for (m = 0; m < col; m++) {
                    matrix[i][m] = 0;
                }
            }
        }
    }

    for (i = 0; i < row; i++) {
        free(arr[i]);
    }
    free(arr);
}
```