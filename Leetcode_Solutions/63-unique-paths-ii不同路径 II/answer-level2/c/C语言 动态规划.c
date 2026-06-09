动态规划4步法

```
#define IF_CONDITION_RETURN(condition, retCode) \
    do {                       \
        if ((condition)) {       \
            return (retCode);        \
        }                      \
    } while(0);

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    // 明确状态 -- 走完一步到达的位置pos(i,j)
    // 明确dp含义 -- 到达每个状态 可能的路径数目 dp[i][j]
    // 明确状态转移方程 -- dp[i][j] = (obstacleGrid[i][j] != 1) * (dp[i - 1][j] + dp[i][j - 1]);;
    // 明确 base case -- dp[i][0] = (obstacleGrid[i][0] != 1 && dp[i - 1][0]); dp[0][j] = (obstacleGrid[0][j] != 1 && dp[0][j - 1]);
    int i, j;
    long long **dp = (long long**)malloc(sizeof(long long*) * obstacleGridSize);
    IF_CONDITION_RETURN(dp == NULL, -1);
    
    for (int i = 0; i < obstacleGridSize; i++) {
        dp[i] = (long long*)malloc(sizeof(long long) * obstacleGridColSize[i]);
        IF_CONDITION_RETURN(dp[i] == NULL, -1);
        memset(dp[i], 0, sizeof(long long) * obstacleGridColSize[i]);
    }

    // 初始化 base case
    dp[0][0] = 1 && (obstacleGrid[0][0] != 1);

    for (i = 1; i < obstacleGridSize; i++) {
        // 如果有0 则以后都是0
        dp[i][0] = (obstacleGrid[i][0] != 1 && dp[i - 1][0]);

    }

    for (j = 1; j < obstacleGridColSize[0]; j++) {
        // 如果有0 则以后都是0
        dp[0][j] = (obstacleGrid[0][j] != 1 && dp[0][j - 1]);

    }

    for (int i = 1; i < obstacleGridSize; i++) {
        for (int j = 1; j < obstacleGridColSize[i]; j++) {
            // 当前不能为石头
            dp[i][j] = (obstacleGrid[i][j] != 1) * (dp[i - 1][j] + dp[i][j - 1]);
        }
    }
    return dp[obstacleGridSize - 1][obstacleGridColSize[0] - 1];
}
```
