### 解题思路
注意yield函数相当于一个一次生成一个的生成器，可以记录上次执行的位置，可以用for循环遍历
如果用return的话需一次返回整个列表

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        row_len=len(grid)
        col_len=len(grid[0])
        rot=[]
        for i,row in enumerate(grid):
            for j,val in enumerate(row):
                if val==2:
                    rot.append((i,j,0))
        d=0
        def neighbors(i,j):
            for x,y in ((i+1,j),(i-1,j),(i,j+1),(i,j-1)):
                if 0<=x<row_len and 0<=y<col_len:
                    yield x,y
        while(rot):
            i,j,d=rot.pop(0)
            for r,c in neighbors(i,j):
                if grid[r][c]==1:
                    grid[r][c]=2
                    rot.append((r,c,d+1))
        if any (1 in row for row in grid):
            return -1
        return d
            

            

```