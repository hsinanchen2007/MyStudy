

```
'''
dp(i, i) 表示以i, j位置结尾的最长递增路径长度
'''

from typing import List
class Solution:

    def solve(self, i, j, matrix: List[List[int]], m, n, memo):
        if (i, j) in memo:
            return memo[(i, j)]

        max_len = 0
        for ii, jj in [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]:
            if ii >= 0 and ii < m and jj >= 0 and jj < n and matrix[ii][jj] < matrix[i][j]:
                max_len = max(max_len, self.solve(ii, jj, matrix, m, n, memo))

        memo[(i, j)] = max_len + 1
        return max_len + 1

    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if len(matrix) == 0:
            return 0
        if len(matrix[0]) == 0:
            return 0

        m, n = len(matrix), len(matrix[0])
        ans = -1
        for i in range(m):
            for j in range(n):
                ans = max(ans, self.solve(i, j, matrix, m, n, {}))
        return ans
```
