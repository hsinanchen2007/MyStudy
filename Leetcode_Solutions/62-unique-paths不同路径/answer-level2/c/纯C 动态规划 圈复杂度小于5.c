双100

```
#define IF_CONDITION_RETURN(condition, retCode) \
    do {                       \
        if ((condition)) {       \
            return (retCode);        \
        }                      \
    } while(0);

#define FOR_EACH_ITERM(start, end, code)     \
    for (start = 0; start < end; start++) {  \
        (code);                              \
    }

int uniquePaths(int m, int n){
    // 1、明确状态 -- 每次移动一步到达的位置 pos(i,j)
    // 2、明确dp意义  -- 到达某一状态有多少条路径 
    // 3、dp状态转移方程 -- dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    // 4、base case -- dp[0][j] = 1  dp[i][0] = 1
    int i, j;
    int **dp = (int**)malloc(sizeof(int*) * m);
    IF_CONDITION_RETURN(dp == NULL, -1);
    
    for (int i = 0; i < m; i++) {
        dp[i] = (int*)malloc(sizeof(int) * n);
        IF_CONDITION_RETURN(dp[i] == NULL, -1);
        memset(dp[i], 0, sizeof(int) * n);
    }

    // 初始化 base case
    FOR_EACH_ITERM(i, m, dp[i][0] = 1);
    FOR_EACH_ITERM(i, n, dp[0][i] = 1);

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}
```
