### 解题思路
此处撰写解题思路
找出递推公式，向下向右，假设此时为最小值，则上一个最小值是它的上一个与左一个值中最小值加上当前值
因此dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]
为了使得i-1与j-1有效，可以先把第一行与第一列算出来，因为这些值是确定的，再从i=1,j=1遍历并按照递推公式进行计算。
### 代码

```java
class Solution {
    public int minPathSum(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int[][] dp = new int[n][m];
        dp[0][0] = grid[0][0];
        for(int i = 1; i < n; i++){
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for(int j = 1; j < m; j++){
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[n - 1][m - 1];
    }
}
```