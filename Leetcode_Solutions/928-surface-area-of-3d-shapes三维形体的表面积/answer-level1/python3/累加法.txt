### 解题思路
单独计算每个位置的面积，累加。对于每一个位置，首先判断是否有立方体，有的话必然存在上下两面，面积+2
，然后判断上下左右相邻的位置是否存在立方体，存在则计算面积贡献，
max(当前位置立方体数-相邻位置立方体数，0)，否则则加当前位置立方体数值。若当前位置不存在立方体，
则判断下一个位置。

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        tem = len(grid)
        S = 0
        for i in range(tem):
            for j in range(tem):
                if(grid[i][j]>0):
                    S+=2
                    if(i-1>=0):
                        S+=max(grid[i][j]-grid[i-1][j],0)
                    else:
                        S+=grid[i][j]
                    if(i+1<tem):
                        S+=max(grid[i][j]-grid[i+1][j],0)
                    else:
                        S+=grid[i][j]
                    if(j-1>=0):
                        S+=max(grid[i][j]-grid[i][j-1],0)
                    else:
                        S+=grid[i][j]
                    if(j+1<tem):
                        S+=max(grid[i][j]-grid[i][j+1],0)
                    else:
                        S+=grid[i][j]
                else:
                    continue
        return S
                

```