采用了long long型变量，因为计算过程中int有溢出的情况。

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0) return 0;
        if (obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;

        vector<long long> dp(n);
        dp[0] = 1;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (obstacleGrid[i][j] == 1) dp[j] = 0;
                else if (j) dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }
};