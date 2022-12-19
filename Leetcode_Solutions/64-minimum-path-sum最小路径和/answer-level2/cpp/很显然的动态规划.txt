到点(i,j)的最小数字总和等于min(到点(i-1,j)的最小数字总和，到点(i,j-1)的最小数字总和)+点(i,j)的值。
用动态规划就很简单了，当然要处理一下边界值。

```C++ []
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		vector<vector<int>> dp(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {		
				int res = 0;
				if (i == 0 && j > 0)
					res = dp[i][j - 1];
				else if (j == 0 && i > 0)
					res = dp[i - 1][j];
				else if (i > 0 && j > 0)
					res = min(dp[i][j - 1], dp[i - 1][j]);
				dp[i][j] = res + grid[i][j];
			}
		}
		return dp[n - 1][m - 1];
	}
};
```
