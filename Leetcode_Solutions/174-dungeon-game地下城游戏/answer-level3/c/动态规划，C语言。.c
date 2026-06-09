### 解题思路
算法思想就是**动态规划**。
我们创建一个二维数组，dp[i][j]是到达第（i+1）行第（j+1）个格子前需要的最低hp。
易知，除了最后一行和最后一列，每个格子都可以向下或者向右，那么只要知道了右边格子的dp值和
下边格子的dp值，再结合该格的hp变化值，就能得出该格的dp值。（具体转移方程见代码注释）

### 代码

```c
int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize){
    int R = dungeonSize, C = *dungeonColSize;
    int dp[R][C];
    
    /* dp[i][j]:到达第i行第j个格子前需要的最低hp */
    /* dp[i][j] + dungeon[i][j] >= dp[i + 1][j] */
    /* dp[i][j] + dungeon[i][j] >= dp[i][j + 1] */
    /* 上述两个式子满足其一即可，以及要保证任何时候的dp都是大于0的 */
    
    dp[R - 1][C - 1] = 1 - min(dungeon[R - 1][C - 1], 0);
    
    for (int i = R - 2; i >= 0; i--)           /* 初始化最后一列 */
        dp[i][C - 1] = max(dp[i + 1][C - 1] - dungeon[i][C - 1], 1);
    
    for (int i = C - 2; i >= 0; i--)           /* 初始化最后一行 */
        dp[R - 1][i] = max(dp[R - 1][i + 1] - dungeon[R - 1][i], 1);
    
    for (int i = R - 2; i >= 0; i--)
        for (int j = C - 2; j >= 0; j--)
            dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
    
    return dp[0][0];
}
```