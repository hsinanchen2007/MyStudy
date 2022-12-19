递归

### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        ans = 0
        lenx, leny = len(grid)-1, len(grid[0])-1
        def check(x, y):
            
            if grid[x][y] == 0:
                return 0
            else:
                grid[x][y] = 0
                a, b, c, d = 0,0,0, 0
                if y != 0:
                    a += check(x, y-1)
                if y != leny:
                    b += check(x, y+1)
                if x != lenx:
                    c += check(x+1, y)
                if x != 0:
                    c += check(x-1, y)
                return a+b+c+d+1
    

        for x, xv in enumerate(grid):
            for y, v in enumerate(xv):
                if v == 1:
                    ans = max(ans, check(x, y))
        return ans
```