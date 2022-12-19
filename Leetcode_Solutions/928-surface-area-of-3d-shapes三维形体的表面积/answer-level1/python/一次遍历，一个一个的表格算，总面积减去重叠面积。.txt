### 解题思路
思路，总面积减去重叠面积，每个格子检查左边和上面有没有正方体。

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        ans=0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                ans+=6*grid[i][j]
                if grid[i][j]>=1:
                    ans-=(grid[i][j]-1)*2
                if i>=1:
                    ans-=min(grid[i][j],grid[i-1][j])*2
                if j>=1:
                    ans-=min(grid[i][j-1],grid[i][j])*2
        return ans 

```