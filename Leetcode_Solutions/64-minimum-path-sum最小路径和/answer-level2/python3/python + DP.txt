```python
from typing import List
class Solution:
	def minPathSum(self, grid: List[List[int]]) -> int:
		row, col = len(grid), len(grid[0])
		dp = [0] * col
		for i in range(row):
			for j in range(col):
				if i == 0 and j == 0: dp[j] = grid[i][j]
				elif j == 0: dp[j] = dp[j]  + grid[i][j]
				elif i == 0: dp[j] = dp[j - 1] + grid[i][j]
				else: dp[j] = min(dp[j], dp[j - 1]) + grid[i][j]
		return dp[-1]
```