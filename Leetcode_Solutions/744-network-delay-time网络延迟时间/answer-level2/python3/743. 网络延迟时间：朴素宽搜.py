![image.png](https://pic.leetcode-cn.com/8a2902c1baa6b18c3224bb5c6883f7bd9f10c75aed29026fab02b0d7d89a0c36-image.png)

536ms，99%仅供参考，宽搜的若干种写法，线上测试第一种最快，第二种最短。

线下测试，速度上第二、三、四种宽搜写法时间差不多，约为第一种方法两倍的时间，最后一种专用于多线程的队列，在一般算法题里不推荐使用，平均时间是第一种5-8倍。

另外，这题说是`N`最大可以取`100`，其实测试数据最大只有`75`而已。

随手撸的宽搜，感觉比较像SPFA，但还不太确定。

```python []
class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        d = [{} for _ in range(N + 1)]
        for i, j, k in times:
            d[i][j] = k
        v = [0] + [float('inf')] * N
        v[K], q = 0, {K}
        while q:
            t = set()
            for i in q:
                for j in d[i]:
                    if v[i] + d[i][j] < v[j]:
                        v[j] = v[i] + d[i][j]
                        t.add(j)
            q = t
        ans = max(v)
        return [-1, ans][ans < float('inf')]
```
```python []
class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        d = [{} for _ in range(N + 1)]
        for i, j, k in times:
            d[i][j] = k
        v = [0] + [float('inf')] * N
        v[K], q = 0, [K]
        for i in q:
            for j in d[i]:
                if v[i] + d[i][j] < v[j]:
                    v[j] = v[i] + d[i][j]
                    q.append(j)
        ans = max(v)
        return [-1, ans][ans < float('inf')]
```
```python []
class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        d = [{} for _ in range(N + 1)]
        for i, j, k in times:
            d[i][j] = k
        v = [0] + [float('inf')] * N
        v[K], q = 0, [K]
        while q:
            i = q.pop(0)
            for j in d[i]:
                if v[i] + d[i][j] < v[j]:
                    v[j] = v[i] + d[i][j]
                    q.append(j)
        ans = max(v)
        return [-1, ans][ans < float('inf')]
```
```python []
class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        d = [{} for _ in range(N + 1)]
        for i, j, k in times:
            d[i][j] = k
        v = [0] + [float('inf')] * N
        v[K], q = 0, collections.deque([K])
        while q:
            i = q.popleft()
            for j in d[i]:
                if v[i] + d[i][j] < v[j]:
                    v[j] = v[i] + d[i][j]
                    q.append(j)
        ans = max(v)
        return [-1, ans][ans < float('inf')]
```
```python []
import queue
class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        d = [{} for _ in range(N + 1)]
        for i, j, k in times:
            d[i][j] = k
        v = [0] + [float('inf')] * N
        v[K], q = 0, queue.Queue()
        q.put(K)
        while q.qsize():
            i = q.get()
            for j in d[i]:
                if v[i] + d[i][j] < v[j]:
                    v[j] = v[i] + d[i][j]
                    q.put(j)
        ans = max(v)
        return [-1, ans][ans < float('inf')]
```