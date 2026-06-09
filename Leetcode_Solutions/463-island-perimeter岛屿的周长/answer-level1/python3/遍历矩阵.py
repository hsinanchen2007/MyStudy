### 解题思路
对于每个为1的格子，判断上下左右是否是陆地，如果不是就说明是边界！

### 代码

```python3
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0

        ans=0
        m, n = len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j]==1:
                    for x,y in [(1,0),(-1,0),(0,1),(0,-1)]:
                        new_i=i+x
                        new_j=j+y
                        if new_i<0 or new_i>=m or new_j<0 or new_j>=n or grid[new_i][new_j]==0:
                            ans+=1
        return ans
```