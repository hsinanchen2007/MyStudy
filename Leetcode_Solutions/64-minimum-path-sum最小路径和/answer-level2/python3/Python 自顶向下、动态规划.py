### 解题思路

因为是自顶向下递归，所以只需要判断下边界即可，就是 i == m or j == n 的边界。

### 代码

```python3
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        ans = [[-1] * n for _ in range(m)]
        ans[m-1][n-1] = grid[m-1][n-1]

        def recursion(i, j):
            if i == m or j == n:
                return float('inf')
            if ans[i][j] == -1:
                ans[i][j] = grid[i][j] + min(recursion(i+1, j), recursion(i, j+1))
            return ans[i][j]
        recursion(0, 0)

        return ans[0][0]
```