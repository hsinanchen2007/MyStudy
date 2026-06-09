### 解题思路
这就是严谨的java吗，i了i了，思路和C++一致，但判断和强制转换要严谨很多。

### 代码

```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        if (m == 0) return 0;
        int n = obstacleGrid[0].length;
        if (n == 0) return 0;

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

        long[] dp = new long[n];
        dp[0] = 1;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++) {
                if (obstacleGrid[i][j] == 1) dp[j] = 0;
                else if (j>0) dp[j] += dp[j-1];
            }
        }
        return (int)dp[n-1];
    }
}
```