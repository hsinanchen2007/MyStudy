### 解题思路
使用bfs的思路去解决，这个问题主要是有多个起点，都将起点将入到queue中就行更新就好了

### 代码

```python3
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        st = [[False]*m for i in range(n)]
        queue = []
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    st[i][j] = True
                    queue.append((i, j , 0))
        if len(queue) == 0 or len(queue) == n * m: # 特判
            return -1
        
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]

        while queue:
            x, y, dis = queue.pop(0)
            for i in range(4): # 四个方向
                a = x + dx[i]
                b = y + dy[i]
                if a < 0 or b < 0 or a >= n or b >=m or st[a][b]: 
                    continue
                queue.append((a, b, dis + 1))
                st[a][b] = True # 访问过的位置标记为 True
                
        return dis
```