### 解题思路
没有什么高大上的解法，直接按花费时间放到最小堆即可。

### 代码

```python3
import heapq
class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        adj = {}
        for cur, nxt, cost in times:
            adj[cur] = adj.get(cur, []) + [(nxt, cost)]
            
        heap = [(0, K)]
        visited = set()
        res = 0
        cnt = 0
        while heap:
            cost, cur = heapq.heappop(heap)
            if cur not in visited:
                res = cost
                cnt += 1
                visited.add(cur)
                for nxt in adj.get(cur, []):
                    heapq.heappush(heap, (cost+nxt[1], nxt[0]))
        # print(cnt)
        if cnt == N:
            return res
        return -1
```