### 解题思路
样例输入[[1,2],[3,4]]， 这里的1意思是第一行第一列有一个立方体，2意思是第一行第二列有2个立方体，3的意思是第二行第一列有3个立方体。

判断3种重复
1、上下立方体之间
2、同列相邻行之间
3、同行相邻列之间

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        res = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j]>0:
                    res += (grid[i][j]*4+2)
                    if i-1>=0 and len(grid[i-1])>j:
                        res -= min(grid[i][j],grid[i-1][j])*2
                    if j>0:
                        res-= min(grid[i][j],grid[i][j-1])*2
        return res

            
```