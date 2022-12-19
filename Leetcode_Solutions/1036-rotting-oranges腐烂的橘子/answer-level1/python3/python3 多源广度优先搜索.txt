### 解题思路
与官方题解2思路类似，细节见代码注释
时间复杂度：O(mn)
空间复杂度：O(mn)

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        res=0  #当前分钟数
        count=0   #新鲜橘子数量
        m=len(grid)   #网格行数
        n=len(grid[0])   #网格列数
        queue=collections.deque()   #BFS队列，储存腐烂橘子所在网格的坐标
        for i in range(m):     #遍历网格一遍，初始化0分钟时刻的队列和新鲜橘子数量
            for j in range(n):
                if grid[i][j]==2:
                    queue.append([i,j])
                if grid[i][j]==1:
                    count+=1

        #开始BFS搜索，将腐烂橘子周围(上、下、左、右依次判断)的新鲜橘子腐烂
        length=len(queue)
        while queue:   
            for _ in range(length):
                x,y=queue.popleft()
                if x-1>=0 and grid[x-1][y]==1:
                    grid[x-1][y]=2
                    queue.append([x-1,y])
                    count-=1
                if y-1>=0 and grid[x][y-1]==1:
                    grid[x][y-1]=2
                    queue.append([x,y-1])
                    count-=1
                if x+1 < m and grid[x+1][y]==1:
                    grid[x+1][y]=2
                    queue.append([x+1,y])
                    count-=1
                if y+1 < n and grid[x][y+1]==1:
                    grid[x][y+1]=2
                    queue.append([x,y+1])
                    count-=1
            length=len(queue)
            if length!=0:
                res+=1

        #BFS完成后，若新鲜橘子数大于0，则说明有橘子未被腐烂，返回-1；否则返回最后的分钟数res
        return res if count==0 else -1   
```