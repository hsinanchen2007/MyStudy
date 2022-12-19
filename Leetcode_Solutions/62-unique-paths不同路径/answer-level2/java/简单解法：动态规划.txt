动态规划
除了第一行和第一列，剩下的点,比如说到达m[i][j]的路径数量,
就等于到达它的正上方和到达它左边,这两个点的路径之和,
也就是dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

```
class Solution {

    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                }else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
    return dp[m - 1][n - 1];
    
    //空间优化写法
    public int uniquePaths(int m, int n) {
        int[] dp = new int[n];
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0){
                    dp[j] = 1;   
                }else {
                    dp[j] = dp[j] + dp[j - 1];
                }
            }
        }
        return dp[n - 1];   
    }
}
```

