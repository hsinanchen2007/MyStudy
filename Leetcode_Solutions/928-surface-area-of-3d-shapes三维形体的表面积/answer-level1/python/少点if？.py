### 解题思路
抖个机灵，我选择加上一圈0少点if😄

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        n = len(grid)
        grid = [[0]+x+[0] for x in grid]
        grid[0:0] = [[0]*(n+2)]
        grid.append([0]*(n+2))
        ans = 0
        for i in range(1, n+1):
            for j in range(1, n+1):
                num = grid[i][j]
                if num!=0:
                    ans += 4*num+2-min(grid[i-1][j], num)-min(grid[i+1][j], num)\
                    -min(grid[i][j-1], num)-min(grid[i][j+1], num)

        return ans
```