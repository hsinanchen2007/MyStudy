感觉不需要初始化一个`mxn`的矩阵, 直接构造一个集合保存能够访问的点就可以
最后结果就是这个集合中元素的个数

```python
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        def getSum(i, j):
            res = 0
            while i:
                res += i % 10
                i //= 10
            while j:
                res += j %10
                j //= 10
            return res
        
        from collections import deque
        que = deque()
        que.append((0, 0))
        visited = set()
        while que:
            i, j = que.popleft()
            if (i, j) not in visited and getSum(i, j) < k + 1:
                visited.add((i, j))
                for di, dj in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                    if -1< i + di < m and -1 < j + dj < n:
                        que.append((i+di, j+dj))
        return len(visited)

```