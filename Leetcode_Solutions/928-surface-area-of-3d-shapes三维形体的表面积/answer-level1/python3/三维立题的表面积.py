### 解题思路
此处撰写解题思路
读题一小时，解题五分钟

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        if rows == 0 or cols == 0:
            return 0
        sumnumber,vecOverlap = 0,0
        for i in range (0,rows):
            for j in range (0,cols):
                sumnumber += grid[i][j]
                if grid[i][j]>0:
                    vecOverlap += grid[i][j]-1
                if i>0:
                    vecOverlap += min(grid[i-1][j],grid[i][j])
                if j>0:
                    vecOverlap += min(grid[i][j-1],grid[i][j])
        return (sumnumber*6 - vecOverlap*2)
                
                




```