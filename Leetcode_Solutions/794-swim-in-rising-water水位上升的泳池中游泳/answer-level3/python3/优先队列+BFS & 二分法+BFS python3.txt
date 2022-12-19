参考花花酱 C++改写成python3 https://zxi.mytechroad.com/blog/?s=778

方法1：优先队列+BFS
```python
import heapq
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        q = [] # {-time, y * N + x} C++中优先队列是大顶堆,python中是小顶堆，使用y*N+x表示坐标，节省一维
        heapq.heappush(q,(grid[0][0],0*n+0)) 
        seen = [0]*(n**2)
        dirs = [-1,0,1,0,-1] # 方向数组，这个方向数组绝了
        seen[0+0*n] = 1
        # BFS
        while q:
            node = heapq.heappop(q)
            t = node[0]
            x = node[1] % n
            y = node[1] // n
            if x == n - 1 and y == n - 1:
                return t
            for i in range(4):
                tx = x + dirs[i]
                ty = y + dirs[i+1]
                if tx < 0 or ty < 0 or tx >= n or ty >= n:
                    continue
                if seen[ty*n+tx]:
                    continue
                seen[ty*n+tx] = 1
                heapq.heappush(q,(max(t,grid[ty][tx]),ty*n+tx))
        return -1
```
方法2：二分搜索+BFS
```python
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        def hasPath(t):
            if grid[0][0]>t:
                return False
            q = []
            seen = [0]*(n**2)
            dirs = [1, 0, -1, 0, 1]
            q.append(0)
            while q:
                x = q[-1] % n
                y = q[-1] // n
                q.pop()
                if x == n - 1 and y == n - 1:
                    return True 
                for i in range(4):
                    tx = x + dirs[i]
                    ty = y + dirs[i+1]
                    if tx < 0 or ty < 0 or tx >=n or ty >= n or grid[tx][ty]>t:
                        continue
                    key = ty*n + tx
                    if seen[key]:
                        continue
                    seen[key] = 1
                    q.append(key)
            return False

        l = 0
        r = n * n 
        while l < r:
            m = l + (r - l) // 2
            if hasPath(m):
                r = m 
            else:
                l = m + 1
        return l
```