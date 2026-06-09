### 解题思路
求最值，二维数组上的动态规划：这里采用自底向上的算法（因为要求的到达右下角的礼物价值）
因为每次只能向右或者向下，因此状态转移方程很容易看出来：
令dp[i][j]表示当前i j处的最大礼物价值
dp[i][j] = grid[0][0], i==0 && j == 0
         = grid[i-1][j], i!=0 && j == 0
         = grid[i][j-1], i==0 && j != 0
         = Math.max(dp[i-1][j], dp[i][j-1]) + grid[i][j]
搞定！！！

### 代码

```java
class Solution {
    public int maxValue(int[][] grid) {      
        if(grid.length == 0 || grid[0].length == 0){
            return 0;
        }
        int ans = 0;
        int m = grid.length;
        int n = grid[0].length;
        int[][] dp = new int[m][n];       
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[0][0];
                    continue;
                }
                if(i == 0){
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                    continue;
                }
                if(j == 0){
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                    continue;
                }
                dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
}
```