用记忆化搜索的方式实现动态规划，慢的一批
```
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        m = len(matrix)
        if m == 0: return 0
        n = len(matrix[0])

        dp = [[-1] * n for _ in range(m)]

        self.res = 0
        def dfs(i, j):
            if not (0 <= i < m and 0 <= j < n): return 0
            if dp[i][j] != -1: return dp[i][j]
            a, b, c  = dfs(i - 1, j), dfs(i, j - 1), dfs(i - 1, j - 1) 
            if matrix[i][j] == 1:
                dp[i][j] = min(a, b, c) + 1
                self.res += dp[i][j]        
            else:
                dp[i][j] = 0

            
            return dp[i][j]

        tmp = dfs(m - 1, n - 1)
        return self.res
```
