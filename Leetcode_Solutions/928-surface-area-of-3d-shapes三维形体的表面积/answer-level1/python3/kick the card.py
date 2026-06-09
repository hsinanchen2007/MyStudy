### 解题思路
punch in the card. 
Again, I will give you the code. 

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        if len(grid)==0:
            return 0;
        area=0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j]==0:
                    continue
                area+=2
                area+=4*grid[i][j]
                if j > 0:
                    area-=2*min(grid[i][j],grid[i][j-1])
                if i>0 and j<len(grid[i-1]):
                    area-=2*min(grid[i][j],grid[i-1][j])
        return area

```