//1.状态：网格大小m n  选择：向右或向下
//2.dp[i][j]=x 表示从起点到grid[i][j]的最小路径和为x
//  base case: dp[0][j]=grid[0][0]+...+grid[0][j]
//             dp[i][0]=grid[0][0]+...+grid[i][0]
//3.转移方程：dp[i][j]=min(dp[i-1][j], dp[i][j-1])+grid[i][j]
```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];  //防止grid[0][0]重复加
        //base case
        for(int i = 1; i < m; ++ i) {
            for(int k = 0; k <= i; ++ k)
                dp[i][0] += grid[k][0];
        }
        for(int j = 1; j < n; ++ j) {
            for(int k = 0; k <= j; ++ k)
                dp[0][j] += grid[0][k];
        }
        //转移方程
        for(int i = 1; i < m; ++ i) {
            for(int j = 1; j < n; ++ j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
```
