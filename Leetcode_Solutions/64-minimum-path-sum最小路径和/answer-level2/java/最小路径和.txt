执行用时 :3 ms, 在所有 Java 提交中击败了97.98%的用户
内存消耗 :40.1 MB, 在所有 Java 提交中击败了83.93%的用户
动态规划，用一个二维的dp数组存储当前的最短路径，不过看到别的题解里面有一些优化。我的做法就是比较中规中矩吧，好理解一些。
```
class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid[0].length;
        int n = grid.length;
        int[][] dp = new int[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else if(i == 0)
                    dp[i][j] = dp[i][j-1]+grid[i][j];
                else if(j == 0)
                    dp[i][j] = dp[i-1][j]+grid[i][j];
                else
                    dp[i][j] = Math.min(dp[i-1][j],dp[i][j-1])+grid[i][j];

            }
        }
        return dp[n-1][m-1];
    }
}
```
