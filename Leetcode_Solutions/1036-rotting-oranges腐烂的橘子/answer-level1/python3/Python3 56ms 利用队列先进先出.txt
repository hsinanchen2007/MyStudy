### 解题思路
此处撰写解题思路
首先创建一个队列，把烂橘子的位置全部放进去，然后从队列中弹出烂橘子，改变它周围的橘子为烂橘子再存入队列 并设置时间次数
反复如此 直到队列遍历完后  扫描grid 如果有好橘子 则输出-1 没有则输出时间次数
### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m,n,time = len(grid),len(grid[0]),0
        dx = [-1,0,1,0]#设定上下左右四个坐标
        dy = [0,1,0,-1]
        new_grid = []
        for i in range(m):#将烂橘子放入队列
            for j in range(n):
                if grid[i][j] == 2:
                    new_grid.append((i,j,0))
        while new_grid:#遍历队列
            i,j,time = new_grid.pop(0)#利用队列先进先出原则
            for a in range(4):
                x = dx[a] + i
                y = dy[a] + j
                if 0<=x<m and 0<=y<n and grid[x][y] == 1:
                    grid[x][y] = 2
                    new_grid.append((x,y,time+1))
        for g in grid:
            if 1 in g:
                return -1
        return time
```