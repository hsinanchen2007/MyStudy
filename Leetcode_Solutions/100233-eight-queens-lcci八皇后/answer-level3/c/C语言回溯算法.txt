思路:
    N皇后问题是经典的回溯算法练习题（另一个经典问题是全排练问题）。算法和代码本身没什么难的，需要注意的一点，解的每一行是一个字符串，而不是n个字符的数组。
    以题目示例中解为例，解的每一行包含 n + 1 = 4 + 1 = 5个字符，前4个字符是. 或者 Q，最后还有个结尾的'\0'。

代码：

#define MAXSIZE     1000

void AddToRes(char ***res, int *resIndex, int *queue, int size)
{
    int i, j;

    *(res + *resIndex) = (char **)malloc(sizeof(char *) * size);

    for (i = 0; i < size; i++) {
        *(*(res + *resIndex) + i) = (char *)malloc(sizeof(char) * (size+1));
        for (j = 0; j < size; j++) {
            if (j == queue[i]) {
                *(*(*(res + *resIndex) + i) + j) = 'Q';
            } else {
                *(*(*(res + *resIndex) + i) + j) = '.';
            }
        }
        *(*(*(res + *resIndex) + i) + j) = '\0';    /* 解的每一行是个字符串 */
    }

    (*resIndex)++;

    return;
}

bool CheckOK(int *queue, int row, int column)
{
    int i;

    for (i = 0; i < row; i++) {
        if ((queue[i] == column) ||
            (queue[i] + row == i + column) ||
            (queue[i] - column == row - i)) {
                return false;
            }
    }

    return true;
}

void BackTrace(int *queue, int row, int size, char ***res, int *resIndex)
{
    int i;

    for (i = 0; i < size; i++) {
        if (!CheckOK(queue, row, i)) {
            continue;
        }
        queue[row] = i;
        if (row == size - 1) {
            AddToRes(res, resIndex, queue, size);
        } else {
            BackTrace(queue, row + 1, size, res, resIndex);
        }
    }

    return;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    int *queue = NULL;
    char ***res = NULL;
    int *columnSize = NULL;
    int i;

    *returnSize = 0;
    res = (char ***)malloc(sizeof(char **) * MAXSIZE);
    memset(res, 0, sizeof(int **) * MAXSIZE);

    queue = (int *)malloc(sizeof(int) * n);
    memset(queue, 0, sizeof(int) * n);

    BackTrace(queue, 0, n, res, returnSize);

    columnSize = (int *)malloc(sizeof(int) * (*returnSize));
    memset(columnSize, 0, sizeof(int) * (*returnSize));
    for (i = 0; i < *returnSize; i++) {
        columnSize[i] = n;
    }
    *returnColumnSizes = columnSize;

    free(queue);

    return res;
}