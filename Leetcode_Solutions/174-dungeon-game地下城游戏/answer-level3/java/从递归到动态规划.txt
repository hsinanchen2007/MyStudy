递归解法（会超时）
```
int ans = Integer.MIN_VALUE;
public int calculateMinimumHP1(int[][] dungeon) {
    int m = dungeon.length - 1, n = dungeon[0].length - 1;
    dfs(dungeon, m, n, Math.min(dungeon[m][n], 0));
    ///ans是个负值，由于骑士至少需要1点体力值，所以需要加1
    return -ans + 1;
}

private void dfs(int[][] dungeon, int i, int j, int sum) {
    if (i == 0 && j == 0) {
        ans = Math.max(ans, sum);
        return;
    }
    if (i - 1 >= 0) {
        dfs(dungeon, i - 1, j, Math.min(sum + dungeon[i-1][j], 0));
    }
    if (j - 1 >= 0) {
        dfs(dungeon, i, j - 1, Math.min(sum + dungeon[i][j-1], 0));
    }
}
```
动态规划（AC）
```
public int calculateMinimumHP(int[][] dungeon) {
    int m = dungeon.length - 1, n = dungeon[0].length - 1;
    int[][] dp = new int[m + 1][n + 1];
    dp[m][n] = Math.min(dungeon[m][n], 0);
    ///初始化最后一列
    for (int i = m - 1; i >= 0; i--) {
        dp[i][n] = Math.min(dp[i+1][n] + dungeon[i][n], 0);
    }
    // 初始化最后一行行
    for (int i = n - 1; i >= 0; i--) {
        dp[m][i] = Math.min(dp[m][i+1] + dungeon[m][i], 0);
    }
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            dp[i][j] = Math.min(Math.max(dp[i + 1][j], dp[i][j+1]) + dungeon[i][j], 0);
        }
    }
    return -dp[0][0] + 1;
}
```

