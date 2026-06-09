### 解题思路
直接使用Dijkstra即可

### 代码

```python3
class Solution:
    def shortestAlternatingPaths(self, n: int, red_edges: List[List[int]], blue_edges: List[List[int]]) -> List[int]:

        dist = [[float('inf') for _ in range(2)] for _ in range(n)]
        dist[0][0] = 0
        dist[0][1] = 0

        ga, gb = collections.defaultdict(list), collections.defaultdict(list)
        for u, v in red_edges:
            ga[u].append(v)
        for u, v in blue_edges:
            gb[u].append(v)

        q = [(1, u, 0) for u in ga[0]] + [(1, u, 1) for u in gb[0]]
        heapq.heapify(q)
        while q:
            d, u, c = heapq.heappop(q)
            dist[u][c] = min(dist[u][c], d)
            nc = c ^ 1
            for v in (ga[u] if c == 1 else gb[u]):
                nd = d + 1
                if nd < dist[v][nc]:
                    dist[v][nc] = nd
                    heapq.heappush(q, (nd, v, nc))

        return [min(d) if min(d) < float('inf') else -1 for d in dist]
```