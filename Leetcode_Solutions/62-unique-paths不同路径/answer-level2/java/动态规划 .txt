初始条件 i=0,j=0    dp[0][0] = 1；
子问题递增    if i==0  dp[i][j] = dp[i][j-1];
            if j==0  dp[i][j]= dp[i-1][j];
            if  i!=0 and j!=0   dp[i][j] = dp[i-1][j] + dp[i][j-1];


```

class Solution {
    public int uniquePaths(int m, int n) {
        if (m == 0 && n == 0)
            return 0;
        if (m == 0 || n == 0) 
            return 1;
        
        int[][] dp  = new int[m][n];
        dp[0][0] = 1;
        int i,j;
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (i==0&&j==0) 
                    continue;
                if (i == 0) {
                    dp[i][j] = dp[i][j-1];
                } else if (j == 0) 
                    dp[i][j] = dp[i-1][j];
                else if (i != 0 && j != 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
}
```
