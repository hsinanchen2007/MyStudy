### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        result = 0

        def connected(r, c):
            ans = []
            if r - 1 >= 0:
                ans.append((r-1, c))
            if r + 1 < row:
                ans.append((r+1, c))
            if c - 1 >= 0:
                ans.append((r, c-1))
            if c + 1 < col:
                ans.append((r, c+1))
            return ans

        def dfs(r, c):
            area = 1
            grid[r][c] = 2
            for v in connected(r, c):
                if grid[v[0]][v[1]] == 1:
                    area += dfs(v[0], v[1])
            return area

        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    curr = dfs(i, j)
                    result = max(curr, result)

        return result

```