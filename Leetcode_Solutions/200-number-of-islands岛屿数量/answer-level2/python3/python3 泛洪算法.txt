### 解题思路
简单说就是利用bfs，遍历所有格子，当某一个格子是“1“的时候，利用bfs探索这个岛内所有的1并标记为visited，如果遇到了另一个标记为”1“并且没有被访问过的
格子，那说明这两个格子必不在一个岛屿上，res+1
### 代码

```
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        row=len(grid)
        col=len(grid[0])
        visited=[[False]*col for _ in range(row)]
        direc=[(0,1),(0,-1),(1,0),(-1,0)]
        res=0
        def bfs(i,j):
            visited[i][j]=True
            for dx,dy in direc:
                newX,newY=i+dx,j+dy
                if 0<=newX<row and 0<=newY<col and grid[newX][newY]=="1" and not visited[newX][newY]:
                    bfs(newX,newY)
        for i in range(row):
            for j in range(col):
                if grid[i][j]=="1" and not visited[i][j]:
                    res+=1
                    bfs(i,j)
        return res
```
