### 解题思路
参考题解里面写的代码。考察转化和抽象能力
要点1 转化成方向字典   d[1]=[(0,1),(0,-1)]
要点2 m=n=1的解决
要点3 bfs 
要点4 能拼接上if ndx==-dx and ndy==-dy:（这个不好理解）
回头补上dfs的解法

### 代码

```python3
class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        m=len(grid)
        n=len(grid[0])

        visit=[[False]*n for i in range(m)]
        if m==1 and n==1:return True
        d=collections.defaultdict(list)
        d[1]=[(0,1),(0,-1)]
        d[2]=[(-1,0),(1,0)]
        d[3]=[(0,-1),(1,0)]
        d[4]=[(0,1),(1,0)]
        d[5]=[(0,-1),(-1,0)]
        d[6]=[(-1,0),(0,1)]
        x,y=0,0
        q=[(x,y)]
        while q:
            x,y =q.pop(0)

            for dx,dy in d[grid[x][y]]:
                nx,ny=x+dx,y+dy
                if 0<=nx<=m-1 and 0<=ny<=n-1 and not visit[nx][ny]:
                    for ndx,ndy in d[grid[nx][ny]]:
                        if ndx==-dx and ndy==-dy:
                            if nx==m-1 and ny==n-1:
                                return True
                            q.append((nx,ny))
            visit[x][y]=True
        return False
```