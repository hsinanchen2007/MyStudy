class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty())
			return 0;
		if (obstacleGrid[0][0] == 1)
			return 0;
		int i, j, m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
		for (i = 1; i <= m; i++)
			for (j = 1; j <= n; j++)
				if (i == 1 && j == 1)
					dp[i][j] = 1;	
				else
					dp[i][j] = obstacleGrid[i - 1][j - 1] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1];
		return dp[m][n];
	}
};