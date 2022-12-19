### 解题思路
此处撰写解题思路
### 代码

```java
class Solution {
    public int minPathSum(int[][] grid) {
        if(grid==null||grid.length==0) return 0;
        int m=grid.length,n=grid[0].length;
        int[]dp=new int[n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0) dp[0]+=grid[i][0];
                else if(i==0) dp[j]=dp[j-1]+grid[0][j];
                else dp[j]=Math.min(dp[j-1],dp[j])+grid[i][j];
            }
        }
        return dp[n-1];
    }
}
```