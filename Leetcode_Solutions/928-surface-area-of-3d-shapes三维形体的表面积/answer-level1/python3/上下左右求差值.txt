### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        n=len(grid)
        ans=0
        for r in range(n):
            for c in range(n):
                if grid[r][c]:
                    ans+=2
                    for dx,dy in ((r-1,c),(r+1,c),(r,c-1),(r,c+1)):
                        if 0<=dx<n and 0<=dy<n:
                            gap=grid[dx][dy]
                        else:
                            gap=0
                        ans+=max(grid[r][c]-gap,0)
        return ans
```