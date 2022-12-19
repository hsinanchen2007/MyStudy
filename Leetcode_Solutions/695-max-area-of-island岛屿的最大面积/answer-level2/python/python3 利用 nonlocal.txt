### 解题思路

本题似乎使用一个不带返回值的 dfs 要更自然一点。Python3 内层函数修改外层函数的不可变类型变量需要关键字 nonlocal。

### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:

        def dfs(i, j):
            nonlocal thisArea
            if 0 <= i < m and 0 <= j < n:
                if grid[i][j] == 1:
                    thisArea += 1
                    grid[i][j] = 0
                    dfs(i + 1, j)
                    dfs(i - 1, j)
                    dfs(i, j - 1)
                    dfs(i, j + 1)
                else:
                    return
            else:
                return 

        m, n = len(grid), len(grid[0])
        maxArea = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] != 0:
                    thisArea = 0
                    dfs(i, j)
                    maxArea = max(maxArea, thisArea)
        
        return maxArea

```