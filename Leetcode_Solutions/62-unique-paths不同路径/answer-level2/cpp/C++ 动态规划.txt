```
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<2 || n<2) return 1;
        int dp[m][n];

        //初始化, 第一行和第一列都初始化为1
        // * 1 1 1 1 1 ...
        // 1 * * * * *
        // 1 * * * * *
        for(int i=1; i<m; i++)
            dp[i][0] = 1;
        for(int i=1; i<n; i++)
            dp[0][i] = 1;

        //计算i行j列的数值
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
        
    }
};
```
