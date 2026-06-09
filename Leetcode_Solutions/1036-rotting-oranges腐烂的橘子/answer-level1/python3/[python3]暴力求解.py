### 解题思路
暴力求解

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        row=len(grid)
        col=len(grid[0])
        bad=[]
        time=0
        res=0
        coord=[[-1,0],[1,0],[0,-1],[0,1]]
        for i in range(row):
            for j in range(col):
                if grid[i][j]==2:
                    bad.append((i,j,time))
        
        while bad:
            x,y,time=bad.pop()
            res=max(time,res)
            for loc in coord:
                new_x=x+loc[0]
                new_y=y+loc[1]
                if 0<=new_x<row and 0<=new_y<col and grid[new_x][new_y]==1:
                    grid[new_x][new_y]=2
                    bad.insert(0,(new_x,new_y,time+1))
            
        for rows in grid:
            if 1 in rows:
                return -1

        return res
            
```