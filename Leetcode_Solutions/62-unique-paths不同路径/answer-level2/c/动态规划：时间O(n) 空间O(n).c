### 解题思路
动态规划：到达路径数等与前两种到达的和
dp[i][j] = dp[i - 1][j] + dp[i][j-1];

### 代码

```c
int uniquePaths(int m, int n){
    if(m == 0 || n == 0)
        return 0;
    // m: colums n: rows
    int i = 1, j = 1, k = 0;
    int **dp = (int **)malloc(n * sizeof(int*));
    for(; k < n; k++){
        dp[k] = (int *)malloc(m * sizeof(int));
        dp[k][0] = 1;
    }
    for(k = 0; k < m; k++)
        dp[0][k] = 1;
    for(i = 1; i < n; i++){
        for(j = 1; j < m; j++){
            dp[i][j] = dp[i - 1][j] + dp[i][j-1];
        }
    }
    int ret = dp[n-1][m-1];
    for(k=0; k < n; k++){
        free(dp[k]);
    }
    free(dp);
    return ret;
}
```