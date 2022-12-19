### 解题思路
和找leetcode200找岛的数量思路类似
但是这里找的岛大小..
每次找到1都要改成0,避免重复计算
### 代码```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        row = len(grid)
        if not row:
            return 0
        col = len(grid[0])
        ans = 0
        def dfs(i, j):
            if i < 0 or i >= row or j < 0 or j >= col or grid[i][j] ==0: 
                return 0
            grid[i][j] = 0
            return 1 + sum([dfs(i + 1, j), 
                            dfs(i - 1, j),
                            dfs(i, j - 1), 
                            dfs(i, j + 1)])
        for i in range(row):
            for j in range(col):
                ans = max(ans, dfs(i, j))
        return ans


```