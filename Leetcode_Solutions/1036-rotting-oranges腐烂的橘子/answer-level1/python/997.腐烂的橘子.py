### 解题思路
- 队列中所有存储烂橘子(i,j,cur_time)，同一趟加入的烂橘子有相同的cur_time
- 逐个出队得到(cur_i,cur_j,cur_time)，做四个方向(i,j)的检查，将新鲜橘子变烂后入队，(i,j,cur_time)
- 队空说明能腐烂的已经腐烂了，检查是否还有新鲜橘子，是则return -1，否则return cur_time

### 代码

```python
class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        r,c,cur_time = len(grid),len(grid[0]),0
        directions = [[0,1],[0,-1],[1,0],[-1,0]]
        queue = []
        
        #加入所有烂橘子，用于广度优先遍历
        for i in range(r):
            for j in range(c):
                if grid[i][j]==2:
                    queue.append((i,j,cur_time))
        
        #开始广度优先遍历
        while queue:
            cur_i,cur_j,cur_time = queue.pop(0)      #队头出队，确保先处理完第0分钟的烂橘子
            for direction in directions:
                i,j = cur_i+direction[0],cur_j+direction[1]
                if 0<=i<r and 0<=j<c and grid[i][j]==1:
                    grid[i][j]=2
                    queue.append((i,j,cur_time+1))
        #检查新鲜橘子
        for r in grid:
            if 1 in r:
                return -1

        #确认没有新鲜橘子了
        return cur_time        
```