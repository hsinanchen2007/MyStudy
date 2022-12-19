### 解题思路
一句话：一圈一圈的感染，这是广度遍历的特征。
例如deque或者list都可以模拟队列入队出队先进先出的实现！

首先先找出已经感染的橘子，也就是time == 0时候，将这些橘子入队，然后每次取出队头的感染橘子，对其四周进行感染，这里要注意的是数组的越界判断。
最后当队空时进行判断，如果grid中还有新鲜橘子，那么感染失败，返回-1，否则返回最后出队的橘子的time。

**注：可以联系树来思考，每一个结点作为已经感染的橘子，它的子节点表示它四周的橘子。然后一层一层的进行感染。如果是采用深度遍历的话，那么就不能满足每一轮感染的橘子都发生感染，与题意不符了**

### 代码

```python
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        from collections import deque
        directions = [(-1,0),(1,0),(0,-1),(0,1)]
        m,n,time = len(grid),len(grid[0]),0
        result = deque()
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    result.append((i,j,time))
        while result:
            x,y,time = result.popleft()
            for direction in directions:
                x_new,y_new = x+direction[0],y+direction[1]
                if 0 <= x_new < m and 0 <= y_new < n and grid[x_new][y_new] == 1:
                    grid[x_new][y_new] = 2
                    result.append((x_new,y_new,time+1))
        for row in grid:
            if 1 in row:
                return -1
        return time 


        
```