### 解题思路
使用队列模拟感染路线，先进先出（FIFO）的感染。

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = collections.deque()

        h, w = len(grid), len(grid[0])
        for i in  range(h):
            for j in range(w):
                if grid[i][j] == 2:
                    q.append(((i,j),0))
        ans = 0
        while q:
            (i,j), l = q.popleft()
            # print(i,j,l)
            if l > ans:
                ans = l
            
            if i-1 >=0 and grid[i-1][j] == 1:
                grid[i-1][j] = 2
                q.append(((i-1,j),l+1))
            if i+1 < h and grid[i+1][j] == 1:
                grid[i+1][j] = 2
                q.append(((i+1,j),l+1))
            if j - 1 >=0 and grid[i][j-1] == 1:
                grid[i][j-1] = 2
                q.append(((i,j-1),l+1))
            if j +1 < w and grid[i][j+1] == 1:
                grid[i][j+1] = 2
                q.append(((i,j+1),l+1))
        for i in range(h):
            for j in range(w):
                if grid[i][j] == 1:
                    return -1
        return ans
        
        
```