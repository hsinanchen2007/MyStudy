```python
class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if matrix == [] or matrix == [[]]: return 0
        row, col = len(matrix), len(matrix[0])
        ans = 0
        memo = [[0] * col for _ in range(row)]
        def dfs(parent, i, j):
            if memo[i][j] != 0: return memo[i][j]
            temp_ans = 1
            for x, y in [[i - 1, j], [i, j - 1], [i + 1, j], [i, j + 1]]:
                if 0 <= x < row and 0 <= y < col and matrix[x][y] > matrix[i][j]:
                    temp_ans = max(temp_ans, 1 + dfs(matrix[i][j], x, y))
            memo[i][j] = temp_ans
            return temp_ans

        for i in range(row):
            for j in range(col):
                ans = max(ans, dfs(float('-inf'), i, j))
        return ans     
```