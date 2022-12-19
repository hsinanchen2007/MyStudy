![image.png](https://pic.leetcode-cn.com/7b0f9f762d89faed91b5822799e05b69a0e6b43a6c4515bda7a2a4b3b4ef2f3d-image.png)
```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX 1024
#define VOS_TRUE  1
#define VOS_FALSE 0
char **GenerateRst(int *queueCol, int n)
{
    char** rst = (char**)calloc(n, sizeof(char*));
    for (int i = 0; i < n; i++) {
        rst[i] = (char*)calloc(n+1, sizeof(char));
        memset(rst[i], '.', n);
        rst[i][queueCol[i+1]-1] = 'Q';
    }
    return rst;
}
//判断第row行第col列能否摆放
int CheckQueue(int *queueCol, int row, int col)
{
    //检查已经使用过的列
    for (int i = 1; i <= row; i++) {
        if (queueCol[i] == col || abs(i - row) == abs(queueCol[i] - col)) {
            return VOS_FALSE;
        }
    }
    return VOS_TRUE;
}
void NQueue(int *queueCol, int row, int n, char ***rst, int* returnSize) 
{
    if (row > n) {
        rst[*returnSize] = GenerateRst(queueCol, n);
        (*returnSize)++;
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (CheckQueue(queueCol, row, i) == VOS_FALSE) {
            continue;
        }
        queueCol[row] = i;
        NQueue(queueCol, row+1, n, rst, returnSize);
        queueCol[row] = 0;
    }
}
char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    char ***rst = (char***)calloc(MAX, sizeof(char**));
    *returnSize = 0;
    *returnColumnSizes = (int*)calloc(MAX, sizeof(int));
    int *queueCol = calloc(n+1, sizeof(int));

    NQueue(queueCol, 1, n, rst, returnSize);
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = n;
    }
    return rst;
}
```
