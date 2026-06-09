```
//定义一个dp数组来记录最短路径和
//与62题、63题方法类似
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int dp[][] = new int[m][n];
        dp[0][0] = grid[0][0];
        //初始化第一行最短路径和
        for (int i = 1; i <n; i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        //初始化第一列最短路径和
        for (int j = 1; j < m; j++) {
            dp[j][0] = dp[j - 1][0] + grid[j][0];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = grid[i][j] + Math.min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }
```
