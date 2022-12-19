从右下角到右上角的dp

```Java
class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        //dp[i][j]代表从i,j到右下角至少需要多少健康点数
        // dp[i-1][j-1] =  min(dp[i-1][j],dp[i][j-1]) -dungon[i-1][j-1]
        int rows = dungeon.length;
        int cols = dungeon[0].length;

        int[][] dp = new int[rows+1][cols+1];
        for(int j=0;j<=cols;j++) dp[rows][j]=Integer.MAX_VALUE;
        for(int i=0;i<=rows;i++) dp[i][cols]=Integer.MAX_VALUE;
        dp[rows-1][cols] = 0;
        dp[rows][cols-1] = 0;
        
        for(int i=rows-1;i>=0;i--)
            for(int j=cols-1;j>=0;j--)
                dp[i][j] =  Math.max(0,Math.min(dp[i][j+1],dp[i+1][j]) -dungeon[i][j]);

        return dp[0][0]+1;
    }
}
```