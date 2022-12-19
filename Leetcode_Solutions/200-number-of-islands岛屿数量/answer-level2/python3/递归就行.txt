### 解题思路
和695 是同样的题目

### 代码

```python3
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        ans = 0
        if not grid:
            return ans
        lenx, leny = len(grid)-1, len(grid[0])-1
        def check(x, y):
            if grid[x][y] == "1":
                grid[x][y] = "0"
                if y != 0:
                    check(x, y-1)
                if y != leny:
                    check(x, y+1)
                if x != lenx:
                    check(x+1, y)
                if x != 0:
                    check(x-1, y)

        for x, xv in enumerate(grid):
            for y, v in enumerate(xv):
                if v == "1":
                    check(x, y)
                    ans += 1
        return ans
```