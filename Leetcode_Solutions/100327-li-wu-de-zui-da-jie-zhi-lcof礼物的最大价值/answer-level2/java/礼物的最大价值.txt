### 解题思路
礼物的最大价值，类似于矩阵的最大路径和等等等,某个点的最大价值，可能是从其左边或者上面传过来的值
dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1])+nums[i][j];
### 代码

```java
class Solution {
    //动态规划的思想；
    public int maxValue(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        int[][] dp = new int[row][col];
        dp[0][0] = grid[0][0];
        for(int i=1;i<col;i++){
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        for(int j=1;j<row;j++){
            dp[j][0]=dp[j-1][0]+grid[j][0];
        }
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[row-1][col-1];
    }
}
```