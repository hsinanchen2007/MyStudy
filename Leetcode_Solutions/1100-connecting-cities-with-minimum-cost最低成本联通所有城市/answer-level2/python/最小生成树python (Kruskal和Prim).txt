## 思路:

最小生成树

思路一：`kruskal`算法

思路二：`prim`算法

## 代码:

思路一：

```python
class Solution:
    def minimumCost(self, N: int, connections: List[List[int]]) -> int:
        import heapq
        f = {}

        def find(x):
            f.setdefault(x, x)
            if f[x] != x:
                f[x] = find(f[x])
            return f[x]
        def union(x, y):
            f[find(y)] = find(x)
            
        res = 0
        heap = []
        count = 0
        for x, y, c in connections:
            heapq.heappush(heap, [c, x, y])
        while heap:
            c, x, y = heapq.heappop(heap)
            if find(x) != find(y):
                res += c
                union(x, y)
                count += 1
                if count == N -1:
                    return res
        return  -1
```

思路二：

```python
class Solution:
    def minimumCost(self, N: int, connections: List[List[int]]) -> int:
        from collections import defaultdict
        graph = defaultdict(lambda: defaultdict(lambda: float("inf")))
        for x, y, c in connections:
            graph[x][y] = min(c, graph[x][y])
            graph[y][x] = min(c, graph[y][x])
        heap = [[0, 1]]
        visited = set()
        res = 0
        while heap:
            c, y = heapq.heappop(heap)
            if y in visited: continue
            res += c
            visited.add(y)
            if len(visited) == N:
                return res
            for nxt, c in graph[y].items():
                heapq.heappush(heap, [c, nxt])
        return -1
```

