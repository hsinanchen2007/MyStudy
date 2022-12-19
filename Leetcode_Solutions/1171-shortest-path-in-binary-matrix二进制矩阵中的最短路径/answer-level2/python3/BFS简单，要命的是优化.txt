### 解题思路
  万万没想到我会在简单的BFS上折腾那麽长时间，test里会有几个特别大的矩阵用例，如果不认真优化就会GG
我先说一下基本思路：就是传统的BFS，只不过多了斜着的四个方向罢了；创建矩阵敌人dir，dir[i][j]代表着从(0,0)走到(i,j)的距离，利用队列，将点pop出来然后访问它周围的八个点，对其中没访问过的点push进去，然后做一下判断，如果该点的值更小就不更新，反之更新下值。直到队列空了就返回dir的右下角值即可
  理论上就这么简单，但我直接这么搞AC不了（超时了），有几个优化的坑：
1.队列别用python库，用列表包着元组就行
2.visited一开始就建成和gird一样规模，到后面append
3.队列q不能简单地push，需要将点push进临时建立的temp，等q空了再把temp.copy()赋给q，然后temp清空

### 代码

```python3
class Solution:
    def in_size(self,x,y):
        if(x>=0 and y>=0 and self.n-x>0 and self.n-y>0):
            return True
        return False
    def shortestPathBinaryMatrix(self, grid):
        if(grid[0][0]==1 or grid[len(grid)-1][len(grid)-1]==1):
            return -1
        self.n=len(grid)
        dir=[[1000]*len(grid) for _ in range(len(grid[0]))]
        dir[0][0]=1
        q=[]
        q.append((0,0))
        visited=[[0]*len(grid) for _ in range(len(grid[0]))]
        temp=[]
        dx=[-1,-1,-1, 0, 0, 1, 1, 1]
        dy=[-1, 0, 1,-1, 1,-1, 0, 1]
        while(len(q)):
            (tx,ty)=q.pop()
            for index in range(8):
                x=tx+dx[index]
                y=ty+dy[index]
                if(self.in_size(x, y) and visited[x][y]==0 and grid[x][y] == 0):
                    visited[x][y]=1
                    dir[x][y]=min(dir[tx][ty]+1,dir[x][y])
                    if(x==self.n-1 and y==self.n-1):
                        return dir[self.n-1][self.n-1]
                    temp.append((x,y))
            if(len(q)==0):
                q=temp.copy()
                temp.clear()
        if(dir[self.n-1][self.n-1]==1000):
            return -1
        return dir[self.n-1][self.n-1]
```