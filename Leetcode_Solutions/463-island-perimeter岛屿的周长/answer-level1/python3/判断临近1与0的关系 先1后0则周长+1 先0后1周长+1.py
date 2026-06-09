### 解题思路
加多一圈 防止数组越界 
之后判断临近1与0的关系 先1后0则周长+1 先0后1周长+1
上下左右判断
### 代码

```python3
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        for i in grid:
            i.insert(0,0)
            i.append(0) 
        edge_top = [0 for i in range(len(grid[0])) ]
        edge_bottom = edge_top
        grid.insert(0,edge_top)
        grid.append(edge_top)   #加多一圈 防止数组越界
        num=0
        for i in range(1,len(grid)-1):
            for j in range(1,len(grid[0])-1):
                if (grid[i][j] == 1)&(grid[i-1][j]==0):
                    num = num+1
                if (grid[i+1][j] == 0) & (grid[i][j] == 1):
                    num = num + 1
                if (grid[i][j-1] == 0) & (grid[i][j] == 1):
                    num = num + 1
                if (grid[i][j+1] == 0) & (grid[i][j] == 1):
                    num = num + 1
        return num
```