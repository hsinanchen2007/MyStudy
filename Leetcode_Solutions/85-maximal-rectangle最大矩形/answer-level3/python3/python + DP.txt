```python
from typing import List
class Solution:
	def maximalRectangle(self, matrix: List[List[int]]) -> int:
		if matrix == []: return 0
		row, col = len(matrix), len(matrix[0])
		topOne = [0] * col
		dp = [[0] * (col + 1) for _ in range(row + 1)]
		res = 0
		for i in range(row):
			leftOne = 0
			for j in range(col):
				if matrix[i][j] == '0':
					dp[i + 1][j + 1] = 0
					leftOne = topOne[j] = 0
				else:
					minLeft = float('inf')
					for t in range(topOne[j] + 1):
						minLeft = min(minLeft, dp[i + 1 - t][j])
						res = max(res, (minLeft + 1) * (t + 1))
					leftOne += 1
					topOne[j] += 1
				dp[i + 1][j + 1] = leftOne
			
		return res
```