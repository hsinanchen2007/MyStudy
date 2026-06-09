### 解题思路
判断BFS。
建Q，入队列
建立标记池
循环处理

### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        def counta(n):
            ret = 0
            while n:
                ret += n % 10
                n //= 10
            return ret
        
        from queue import Queue
        q = Queue()
        visited = set()
        q.put((0, 0))
        
        while not q.empty():
            x, y = q.get()
            if (x, y) not in visited and 0<= x < m and 0<= y < n and counta(x) + counta(y) <= k:
                visited.add((x, y))
                for i, j in [(x+1, y), (x, y+1)]:
                    q.put((i, j))
            
        return len(visited)
            
        
```