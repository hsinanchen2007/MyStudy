### 解题思路

### 代码

```cpp
class Solution
{
public:
	int maxValue(vector<vector<int>>& grid)
	{
		int m = grid.size();
		int n = grid[0].size();

		vector<int> dp0(n);
		vector<vector<int>> dp(m, dp0);

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i == 0)			//矩阵第0行
				{
					if (j == 0)
					{
						dp[i][j] = grid[0][0];
					}
					else
					{
						dp[i][j] = dp[i][j - 1] + grid[i][j];
					}
				}
				else if (j == 0)	//矩阵第0列
				{
					dp[i][j] = dp[i - 1][j] + grid[i][j];
				}
				else				//一般情况
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
				}
			}
		}
		return dp[m - 1][n - 1];
	}
};
```