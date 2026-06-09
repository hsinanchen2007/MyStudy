![image.png](https://pic.leetcode-cn.com/6b346f63d73931bd4d640156a435dd7b2b1bdcb01c04f4a5f805a0df7d1a0e2c-image.png)

```
        int m = obstacleGrid.length, n = obstacleGrid[0].length;
        if (m == 0 || n == 0)return 0;
        int[][] dp = new int[m][n];
        //给i行0列赋值
        boolean isFalse = false;
        for (int i = 0; i < m; i++) {
            if (isFalse) {
                dp[i][0] = 0;
            }else if (obstacleGrid[i][0] == 1) {
                isFalse = true;
                dp[i][0] = 0;
            }else {
                dp[i][0] = 1;
            }
        }
        //给0行i列赋值
        boolean isRowFalse = false;
        for (int i = 0; i < n; i++) {
            if (isRowFalse) {
                dp[0][i] = 0;
            }else if (obstacleGrid[0][i] == 1) {
                dp[0][i] = 0;
                isRowFalse = true;
            }else {
                dp[0][i] = 1;
            }
        }
        //如果同列上一个有障碍, 则dp[i][j] = 同行左边的值
        //如果同行左边一个是障碍, 则dp[i][j] = 同列上一个的值
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)return 0;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i-1][j] == 1 && obstacleGrid[i][j-1] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                if (obstacleGrid[i-1][j] == 1) {
                    dp[i][j] = dp[i][j-1];
                }else if (obstacleGrid[i][j-1] == 1) {
                    dp[i][j] = dp[i-1][j];
                }else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
```
