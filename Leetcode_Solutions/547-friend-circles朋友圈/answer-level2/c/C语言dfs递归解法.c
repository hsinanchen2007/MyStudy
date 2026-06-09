### 解题思路
此处撰写解题思路
/* 朋友圈
    思路：总共有N个人， 每个人两两都不是朋友的话，最多有N个朋友圈，
        定义一个N维的数组dp，表示N个朋友圈，值是1表示与其他人建立朋友圈，值是0表示不是朋友。
         深度遍历搜索算法，如果（i,j）是朋友，那就遍历（j,k）是不是朋友，是朋友就把dp[k] = 1;
         然后再遍历(k, ..)跟其他的人是不是朋友；
         dp有几个0值，结果+1， 就为朋友圈的个数

*/

执行用时 :
32 ms
, 在所有 C 提交中击败了
92.98%
的用户
内存消耗 :
8.1 MB
, 在所有 C 提交中击败了
86.52%
的用户

### 代码
int Dfs(int **M, int MSize, int i, int *dp)
{
    if (M == NULL || MSize < 1 || dp == NULL) {
        return false;
    }
    for (int j = 0; j < MSize; j++) {
        int flag = (M[i][j] == 1 && dp[j] == 0);
        if (flag) {
            dp[j] = 1;
            (void)Dfs(M, MSize, j, dp);
        }
    }
    return true;
}
int findCircleNum(int** M, int MSize, int* MColSize)
{
    int flag = (M == NULL || MSize < 1 || MColSize == NULL || MColSize[0] < 1);
    if (flag) {
        return false;
    }   
    int *numcir = (int *)malloc(sizeof(int) * MSize);
    memset(numcir, 0, sizeof(int) * MSize);

    int maxcir = 0;
    for (int i = 0; i < MSize; i++) { 
        if (numcir[i] == 0) {
            maxcir++;
            // printf("\n maxcir=%d i=%d.",maxcir, i);
            (void)Dfs(M, MSize, i, numcir);
        }
    }
    free(numcir);
    return maxcir;
}

```
```c
/* 朋友圈
    思路：总共有N个人， 每个人两两都不是朋友的话，最多有N个朋友圈，
        定义一个N维的数组dp，表示N个朋友圈，值是1表示与其他人建立朋友圈，值是0表示不是朋友。
         深度遍历搜索算法，如果（i,j）是朋友，那就遍历（j,k）是不是朋友，是朋友就把dp[k] = 1;
         然后再遍历(k, ..)跟其他的人是不是朋友；
         dp有几个0值，结果+1， 就为朋友圈的个数

*/
int Dfs(int **M, int MSize, int i, int *dp)
{
    if (M == NULL || MSize < 1 || dp == NULL) {
        return false;
    }
    for (int j = 0; j < MSize; j++) {
        int flag = (M[i][j] == 1 && dp[j] == 0);
        if (flag) {
            dp[j] = 1;
            (void)Dfs(M, MSize, j, dp);
        }
    }
    return true;
}
int findCircleNum(int** M, int MSize, int* MColSize)
{
    int flag = (M == NULL || MSize < 1 || MColSize == NULL || MColSize[0] < 1);
    if (flag) {
        return false;
    }   
    int *numcir = (int *)malloc(sizeof(int) * MSize);
    memset(numcir, 0, sizeof(int) * MSize);

    int maxcir = 0;
    for (int i = 0; i < MSize; i++) { 
        if (numcir[i] == 0) {
            maxcir++;
            // printf("\n maxcir=%d i=%d.",maxcir, i);
            (void)Dfs(M, MSize, i, numcir);
        }
    }
    free(numcir);
    return maxcir;
}

```