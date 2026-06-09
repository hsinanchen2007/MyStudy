### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid: return 0
        ly = len(grid)
        lx = len(grid[0])
        dic = {}
        count = 0
        def clearIs(y,x):
            if grid[y][x] == '1':
                grid[y][x] = '0'
                dic[(y,x)] = 1
                if(y < ly-1):
                    clearIs(y+1,x)
                if(y > 0 ):
                    clearIs(y-1,x)
                if(x < lx-1):
                    clearIs(y,x+1)
                if(x > 0):
                    clearIs(y,x-1)
        for i in range(ly):
            for j in range(lx):
                if grid[i][j] == '1' and (i,j) not in dic:
                    clearIs(i,j)
                    count += 1
        return count
        
                
```