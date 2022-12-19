### 解题思路
障碍物不考虑 全部为零

### 代码

```cpp
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		long long dp[101][101] = { 0 };

		for (int i = 0, t = 1; i < obstacleGrid.size(); i++)if (obstacleGrid[i][0])t = 0; else dp[i][0] = t;
		for (int i = 0, t = 1; i < obstacleGrid[0].size(); i++)if (obstacleGrid[0][i])t = 0; else dp[0][i] = t;

		for (int i = 1; i < obstacleGrid.size(); i++)
			for (int j = 1; j < obstacleGrid[i].size(); j++)
				if (obstacleGrid[i][j])dp[i][j] = 0;
				else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
	}
};
```