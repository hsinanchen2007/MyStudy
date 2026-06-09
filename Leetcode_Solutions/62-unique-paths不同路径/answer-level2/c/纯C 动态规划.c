### 解题思路
动态规划，清清爽爽

### 代码

```c
int uniquePaths(int m, int n){
    /* 
     * 状态方程：f[i][j] = f[i-1][j] + f[i][j-1]
     * 初始条件：f[0][0] = 1
     * 边界情况：i = 0 或 j = 0 时，f[i][j] = 1
     */

    // 依题图意：m为列数,n为行数，倒置无妨
    int indexOfRow = 0;
    int indexOfCol = 0;
    int** ppCount = (int**)malloc(sizeof(int*) * n);
    for (indexOfRow = 0; indexOfRow <= n - 1; indexOfRow++)
    {
        ppCount[indexOfRow] = (int*)malloc(sizeof(int) * m);
    }
    
    for (indexOfRow = 0; indexOfRow <= n - 1; indexOfRow++)
    {
        for (indexOfCol = 0; indexOfCol <= m - 1; indexOfCol++)
        {
            if (0 == indexOfRow || 0 == indexOfCol)
            {
                ppCount[indexOfRow][indexOfCol] = 1;
            }
            else
            {
                ppCount[indexOfRow][indexOfCol] = ppCount[indexOfRow-1][indexOfCol] \
                                                + ppCount[indexOfRow][indexOfCol-1] ;
            }
        }
    }

    return ppCount[indexOfRow-1][indexOfCol-1];
}
```