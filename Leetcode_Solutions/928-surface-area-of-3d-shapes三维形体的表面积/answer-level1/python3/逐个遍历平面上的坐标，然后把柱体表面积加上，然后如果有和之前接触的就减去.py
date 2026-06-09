### 解题思路
逐个遍历平面上的坐标，然后把柱体表面积加上，然后如果有和之前接触的就减去

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        r = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                #print("i:",i,"j:",j)
                if(grid[i][j]>0):
                    r += grid[i][j]*4 + 2
                #print("r:",r)
                try:
                    if(i > 0):
                        r -= min(grid[i-1][j],grid[i][j] )* 2
                        #print("i+")
                except:
                    pass
                try:
                    if(j > 0):
                        r -= min(grid[i][j-1],grid[i][j] )* 2
                        #print("j+")
                except:
                    pass
        return r
    

```