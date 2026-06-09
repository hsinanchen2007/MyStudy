### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:

    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:

        graph = [[] for _ in range(N + 1)]
        dis = [float('inf') for _ in range(N + 1)]
        inq = [False for _ in range(N + 1)]
        for u, v, w in times:
            graph[u].append([v, w])
        dis[K] = 0
        stack = [K]
        while stack:
            node = stack.pop()
            inq[node] = False
            for i in range(len(graph[node])):
                v, w = graph[node][i]
                if dis[node] + w < dis[v]:
                    dis[v] = dis[node] + w
                    if not inq[v]:
                        inq[v] = True
                        stack.append(v)
        return -1 if max(dis[1:]) == float('inf') else max(dis[1:])
```