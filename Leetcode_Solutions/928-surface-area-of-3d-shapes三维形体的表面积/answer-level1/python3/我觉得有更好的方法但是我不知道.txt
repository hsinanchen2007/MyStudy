### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        r = len(grid)
        c = len(grid[0])
        ans = 0
        for i in range(r):
            for j in range(c):
                temp = grid[i][j]
                ans = ans + temp*6
                if temp > 1: ans = ans - (temp-1)*2
                if i+1<r: ans = ans - min(temp, grid[i+1][j])*2
                if j+1<c: ans = ans - min(temp, grid[i][j+1])*2
        return ans
```