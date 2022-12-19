### 解题思路
丑陋的递归

### 代码

```python3
class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        grid = rooms
        if not rooms:
            return ""
        lenx, leny = len(grid)-1, len(grid[0])-1
        def check(x, y, c):
            if grid[x][y] == -1 :
                return 0
            else:
                if grid[x][y] > c:
                    grid[x][y] = c
                elif grid[x][y] != 0 :
                    return ""
                if y != 0 and grid[x][y-1] != 0:
                    check(x, y-1, c+1)
                if y != leny and grid[x][y+1] != 0:
                    check(x, y+1, c+1)
                if x != lenx and grid[x+1][y] != 0:
                    check(x+1, y, c+1)
                if x != 0 and grid[x-1][y] != 0:
                    check(x-1, y, c+1)
          
        for x, xv in enumerate(grid):
            for y, v in enumerate(xv):
                if v == 0:
                    check(x, y, 0)
```