### 解题思路
使用Dijkstra算法求最短路径

### 代码

```python3
class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        #构建邻接矩阵
        dist = [[float("inf") for _ in range(N+1)] for _ in range(N+1)]
        for u, v, w in times:
            dist[u][v] = w
        visited = {K}

        for i in range(N-1):
            mint = float("inf")
            u = K
            #检测距K点距离最小的点u
            for cur in range(1, N+1):
                if cur not in visited and dist[K][cur] < mint:
                    u = cur
                    mint = dist[K][cur]
            visited.add(u)
            #以u为中间点，对剩余点进行路径检测
            for cur in range(1, N+1):
                if cur not in visited and dist[K][u]+dist[u][cur] < dist[K][cur]:
                    dist[K][cur] = dist[K][u]+dist[u][cur]

        return mint if len(visited)==N else -1
```