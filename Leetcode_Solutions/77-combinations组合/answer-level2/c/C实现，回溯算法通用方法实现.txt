```
#define N 10000
void backtrace(int n, int k, int **rst, int *returnSize, int *Columsize, int *arry, int start, int depth);

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    //存储结果
    int **rst = (int**)malloc(sizeof(int*)*N);
    *returnSize  = 0;
    //列
    *returnColumnSizes = (int *)malloc(sizeof(int)*N);
    //记录每次中间结果
    int *arry = (int*) malloc(sizeof(int)*k);
    //回溯
    backtrace(n, k, rst, returnSize, *returnColumnSizes, arry, 1, 0);
    return rst;
}

void backtrace(int n, int k, int **rst, int *returnSize, int *Columsize, int *arry, int start, int depth)
{
    if (n == 0 || k == 0  || (n < k)) {
        return;
    }
    //数深度满足返回结果
    if (depth == k) { 
        rst[*returnSize]  = malloc(sizeof(int)*k);
        memcpy(rst[*returnSize], arry, sizeof(int)*k);
        Columsize[*returnSize] = k;
        (*returnSize)++; 
        return;   
    }
    for (int i = start; i <= n; i++) {
        arry[depth] = i;
        //选择
        depth++;
        //回溯
        backtrace(n, k, rst, returnSize, Columsize, arry, i+1, depth);
        //撤销选择
        depth--;
    }
}

```
