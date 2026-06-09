### 解题思路
回溯

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
static int**res;
static int resLen;

void backTrack(int n, int start, int* tmp, int tmpLen, int** returnColumnSizes)
{
    if (n == 1) {
        if (tmpLen > 1) {
            memcpy(res[resLen], tmp, tmpLen*sizeof(int));
            (*returnColumnSizes)[resLen] = tmpLen;
            resLen++;
        }
        return ;
    }
    for (int i = start; i < n+1 ; i++) {
        if (n % i == 0) {
            tmp[tmpLen] = i;
            tmpLen++;
            backTrack(n/i, i, tmp, tmpLen, returnColumnSizes);
            tmp[tmpLen-1] = 0;
            tmpLen--;
        }
    }
}

int** getFactors(int n, int* returnSize, int** returnColumnSizes){
    res = (int**)malloc(100*sizeof(int*));
    for (int i = 0; i < 100; i++) {
        res[i] = (int*)malloc(32*sizeof(int));
        memset(res[i], 0, 32*sizeof(int));
    }
    resLen = 0;
    int* tmp = (int*)malloc(32*sizeof(int));
    memset(tmp, 0, 32*sizeof(int));
    *returnColumnSizes = (int*)malloc(100*sizeof(int));
    memset(*returnColumnSizes, 0, 100*sizeof(int));
    backTrack(n, 2, tmp, 0, returnColumnSizes);
    *returnSize = resLen;
    return res;
}
```