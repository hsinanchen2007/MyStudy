### 解题思路
经典的Flood Fill问题，借助于队列采用有记录的多源BFS即可

### 代码

```python
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        visited = [[False for _ in range(n)] for _ in range(m)]
        directions = [(-1, 0), (0, -1), (1, 0), (0, 1)]
        queue = collections.deque()
        cnt = 0  # 剩余好橘子数
        # 将初始的坏橘子入队
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    queue.append((i, j))
                    visited[i][j] = True
                elif grid[i][j] == 1:
                    cnt += 1
       
        # 初始就没有好橘子
        if not cnt: return 0
        
        # 初始有好橘子
        minute = 0
        while queue:
            for _ in range(len(queue)):
                cur_i, cur_j = queue.popleft()
                for direct in directions:
                    new_i = cur_i + direct[0]
                    new_j = cur_j + direct[1]
                    if 0<=new_i<m and 0<=new_j<n and grid[new_i][new_j] == 1 and not visited[new_i][new_j]:
                        queue.append((new_i, new_j))
                        visited[new_i][new_j] = True
                        cnt -= 1
            minute += 1
            if not cnt: return minute
        
        return minute if not cnt else -1


```