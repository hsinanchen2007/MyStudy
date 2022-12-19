### 解题思路
因为可以转化成子问题，就是假设每个方格都是左下角的那个格子，考虑这个格子时先把超出这个最左下角的其他的格子擦掉，就会发现这个格子，要么是dp[i-1][j]+grid[i][j]来的，
要么是dp[i][j-1]+grid[i][j]来的，然后取最小值，就是最小距离，然后初始化一下dp数组，就可以了嘿嘿

### 代码

```java
class Solution {
    public int minPathSum(int[][] grid) {
 int[][] dp = new int[grid.length][grid[0].length];
        int sum=0;
        //初始化边界
        for(int i=0;i<grid.length;i++){
            sum+=grid[i][0];
            dp[i][0]=sum;
        }
        sum=0;
    //初始化边界
        for(int i=0;i<grid[0].length;i++){
            sum+=grid[0][i];
            dp[0][i]=sum;
        }
        for(int i=1;i<grid.length;i++)
            for(int j=1;j<grid[0].length;j++){
                dp[i][j]=Math.min(dp[i-1][j]+grid[i][j],dp[i][j-1]+grid[i][j]);
            }
        return dp[grid.length-1][grid[0].length-1];
    }
}
```