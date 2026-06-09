动态规划
思路：初始化第一行和第一列为1,由于第dp[i][j]只能是从左或者上面得到，得到递推公式dp[i][j] = dp[i-1][j]+dp[i][j-1];
```javascript
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];
        for(int i = 0;i<m;i++){
           dp[i][0] = 1;
        }
        for(int i = 0;i<n;i++){
            dp[0][i] = 1;
        }
        for(int i =1;i<m;i++){
            for(int j = 1;j<n;j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    
}
```