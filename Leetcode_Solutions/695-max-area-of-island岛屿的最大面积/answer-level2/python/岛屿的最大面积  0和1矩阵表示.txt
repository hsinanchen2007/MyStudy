### 解题思路
1. 题意非常容易理解，思路也很好规划，但是还是用了40分钟
    - 真正思考并敲代码时间也就15分钟，而是用来25分钟进行代码调试
    - 错误，异常
        - TimeOut(visit[i][j] 设置true时机错误，思考良久)； 
        - 仍然TimeOut，主函数有一个二的continue,造成i和j 不增加了，**这就while的坑，不能轻易continue...，若是遍历元素强烈建议能用for i,val in enumerate() 就用for**
        -  主函数没有return (运行结果None); 






### 代码

#### 第二次书写的代码：
```
# python3
from queue import Queue
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        nsize = len(grid)
        if nsize < 1:
            return 0
        
        msize = len(grid[0])

        visit = [[False]*msize for j in range(nsize)]
        q = Queue()
        max_ = 0
        for i, eles in enumerate(grid):
            for j, ele in enumerate(eles):
                if ele == 1:
                    q.put((i,j))
                    visit[i][j] = True
                    max_ = max( max_, self.bfs(q, visit, grid, nsize, msize) )
                else:
                    continue

        return max_ 
    
    def bfs(self, q, visit, grid, nsize, msize):
        res = 0
        while q.empty() == False:
            i, j = q.get()
            res += 1
            for inci, incj in [(0,-1), (0,1), (-1,0), (1,0)]:
                inext = i + inci
                jnext = j + incj 
                if inext >= 0 and inext < nsize and jnext >=0 and jnext < msize and grid[inext][jnext] == 1 and visit[inext][jnext] == False:
                    q.put((inext, jnext))
                    visit[inext][jnext] = True
                else:
                    pass 
        
        return res 
```

#### 第一次写的代码

```python3
from queue import Queue
class Solution:
    def __init__(self):
        self.visit = None
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        nsize = len(grid)
        if nsize < 1:
            return 0

        msize = len(grid[0])

        self.visit = [[False]*msize for j in range(nsize)]

        i = 0
        max_ = 0
        q = Queue()
        while i < nsize:
            j = 0
            while j < msize:
                if grid[i][j] == 0 or self.visit[i][j]:
                    #continue
                    pass
                else:
                    q.put((i,j))
                    self.visit[i][j] = True
                    max_ = max(max_, self.dfs(q, grid, nsize, msize))
                
                j += 1

            i += 1
        return max_ 
    
    def dfs(self, q, grid, nsize, msize):
        cur = 0
        while q.empty() == False:
            i,j = q.get()
            #self.visit[i][j] = True
            cur += 1
            if i-1 >= 0 and grid[i-1][j] == 1 and self.visit[i-1][j] == False: # left
                q.put((i-1, j))
                self.visit[i-1][j] = True
            if i+1 < nsize and grid[i+1][j] == 1 and self.visit[i+1][j] == False: # right
                q.put((i+1, j))
                self.visit[i+1][j] = True
            if j-1 >= 0 and grid[i][j-1] == 1 and self.visit[i][j-1] == False: # up
                q.put((i, j-1))
                self.visit[i][j-1] = True
            if j+1 < msize and grid[i][j+1] == 1 and  self.visit[i][j+1] == False: # down
                q.put((i, j+1))
                self.visit[i][j+1] = True

        
        return cur 

```