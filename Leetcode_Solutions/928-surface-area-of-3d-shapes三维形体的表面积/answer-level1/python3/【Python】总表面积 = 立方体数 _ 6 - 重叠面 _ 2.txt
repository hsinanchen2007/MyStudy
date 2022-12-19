### 解题思路
总体思路就是总表面积 = 立方体数 * 6 - 重叠面 * 2
重叠面又可以分为两部分：(1)每个格子内的垂直方向上的立方体底/顶面重叠  (2)每个格子之间的立方体的侧面重叠

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        cube = 0
        face = 0
        for i in range(len(grid)):
            for j in range(len(grid)):
                cube += grid[i][j]
                if grid[i][j] > 0:
                    #计算每个格子内垂直方向上的立方体底/顶面重叠
                    face += grid[i][j] - 1
                    #计算每个格子之间的立方体的侧面重叠
                    if i > 0: 
                        face += min(grid[i-1][j], grid[i][j])
                    if j > 0:
                        face += min(grid[i][j-1], grid[i][j])
        return cube * 6 - 2 * face                
```