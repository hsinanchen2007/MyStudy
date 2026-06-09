```
 public int minPathSum(int[][] grid) {

        int length = grid.length;
        int width = grid[0].length;

        if (length == 1 && width == 1) return grid[0][0];

        int[][] dp = new int[length][width];

        // base init
        dp[0][0] = grid[0][0];
        for (int i = 1; i < length; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for (int i = 1; i < width; i++) {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        
        // dp table
        for (int i = 1; i < length; i++) {
            for (int j = 1; j < width; j++) {
                dp[i][j] = Math.min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[length-1][width-1];

    }
```
