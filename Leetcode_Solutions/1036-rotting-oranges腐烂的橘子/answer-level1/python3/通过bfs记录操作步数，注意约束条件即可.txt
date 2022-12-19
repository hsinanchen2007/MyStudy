每次传染后在原数组中把值改为2，再进行bfs，最后返回记录的总步数
```
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        #初始化变量
        res=0
        need=[]
        m=len(grid)
        n=len(grid[0])
        pos=[(1,0),(-1,0),(0,1),(0,-1)]

        #need记录需要操作的橘子
        for i in range(m):
            for j in range(n):
                if grid[i][j]==2:
                    need.append((i,j))

        #bfs 
        queue=[need]
        while queue:
            need=queue.pop(0)
            #cur记录当前操作完成后下一分钟还能操作的橘子
            cur=[]
            for i in need:
                for dx,dy in pos:
                    x=i[0]+dx
                    y=i[1]+dy
                    if 0<=x<m and 0<=y<n and grid[x][y]==1:
                        grid[x][y]=2
                        cur.append((x,y))

            #当前进行过操作则计数+1
            if cur:
                res+=1
                queue.append(cur)

        #全部操作结束后还有好的橘子则返回-1
        for i in range(m):
            if 1 in grid[i]:
                return -1
        return res
```
