### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        """
        BFS
        """
        m,n = len(grid), len(grid[0])
        queue = []
        # 标记已经访问过
        visited = [[0 for _ in range(m)] for _ in range(n)]
        # 收集一下陆地的坐标作为初始的队列
        for i in range(m):
            for j in range(n):
                if grid[i][j]==1:
                    queue.append((i,j))
                    visited[i][j]=1
        # 全0或全1返回
        if not queue or len(queue)==m*n:
            return -1
        
        cnt = 0
        while queue:
            queue_next = []
            for i,j in queue:
                neighbors = [(i-1,j),(i+1,j),(i,j-1),(i,j+1)]
                for neighbor in neighbors:
                    row,col = neighbor
                    # 坐标符合要求且没访问过节点 1的全访问过了所以没访问的是海洋
                    if 0<=row<m and 0<=col<n and visited[row][col]==0:
                        queue_next.append(neighbor)
                        visited[row][col]=1
            queue = queue_next
            cnt+=1
        return cnt-1
```