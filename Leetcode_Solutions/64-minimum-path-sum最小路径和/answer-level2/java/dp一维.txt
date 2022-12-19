### 解题思路
还是之前的思路，选取左侧跟上侧的最小值，加上当前值。

### 代码

```java
class Solution {
    public int minPathSum(int[][] grid) {
        int m=grid.length;

        int n=m==0? 0:grid[0].length;


        int[] dp=new int[n];
        dp[0]=grid[0][0];
        for (int j=1;j<n;j++)
            dp[j]=dp[j-1]+grid[0][j];

        for (int i=1;i<m;i++)
        {
            dp[0]=dp[0]+grid[i][0];
            for (int j=1;j<n;j++)
                dp[j]=Math.min(dp[j],dp[j-1])+grid[i][j];
        }
        return dp[n-1];
    }
}

```