BFS:广度优先搜索（以四邻域为例，先将起始点的四邻域中符合要求的点放入一个集合中，再找这些集合中各个点四邻域中符合要求的点再放入集合中，一层一层的发散出去）
DFS:深度优先搜索（以四邻域按上左下右的顺序为例，先找起始点的上方的点，要是符合要求继续判断这个点上方的点，直至不符合条件，再回溯，回溯至前一个点找他的左边的点，一次判断，遍历，回溯）
通俗来讲，深度优先就是一个方向找到底，再回溯上一层再从它的其他方向继续找，继续回溯；广度优先就是一圈一圈的往外找

BFS：
```
from typing import List
from collections import deque
class Solution:
    directions=[(-1,0),(0,1),(1,0),(0,-1)]
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m=len(grid)          #BFS
        if m==0:
            return 0
        n=len(grid[0])
        judge=[[False for i in range(n)] for i in range(m)]
        max_count=0
        for i in range(m):
            for j in range(n):
                if grid[i][j]==1 and not judge[i][j]:
                    queue=deque()
                    queue.append((i,j))
                    judge[i][j]=True
                    count=1
                    while queue: #一个while表示一个岛屿
                        cur_x,cur_y=queue.popleft()
                        for dire in self.directions:
                            new_x=cur_x+dire[0]
                            new_y=cur_y+dire[1]
                            if 0<=new_x<m and 0<=new_y<n and grid[new_x][new_y]==1 and not judge[new_x][new_y]:
                                queue.append((new_x,new_y))
                                judge[new_x][new_y] = True
                                count+=1
                    max_count=max(count,max_count)
        return max_count
```

DFS：
```
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m=len(grid)
        if m==0:
            return 0
        n=len(grid[0])
        max_=0
        def dfs(i,j):
            if i<0 or i>=m or j<0 or j>=n: return 0
            if grid[i][j]==0:
                return 0
            grid[i][j]=0   #遍历过后就将这个点改为0，避免重复计算
            top=dfs(i-1,j)
            left=dfs(i,j-1)
            down=dfs(i+1,j)
            right=dfs(i,j+1)
            return 1+sum([top,left,down,right])
        for i in range(m):
            for j in range(n):
                max_=max(max_,dfs(i,j))
        return max_
```

