1、求出源点到其它所有点的最小距离，然后对其它点依次判断是否在阈值范围内，统计在阈值范围内的点个数
2、对n个源点均调用Djikstra算法计算阈值内点的个数
```
class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        import heapq

        def Djikstra(source, thresHold):
            BIG = 2**30
            Map = [[BIG] * n for _ in range(n)]
            adj = [[] for _ in range(n)]
            dist = [BIG for _ in range(n)]
            fa = [-1 for _ in range(n)]
            dist[source] = 0

            pq = [(dist[i], i) for i in range(n) if dist[i] < BIG]
            heapq.heapify(pq)

            for i in range(n):
                Map[i][i] = 0
            for a, b, w in edges:
                Map[a][b] = Map[b][a] = w
                adj[a].append(b)
                adj[b].append(a)
            
            while pq:
                Min, u = heapq.heappop(pq)
                for v in adj[u]:
                    alt = dist[u] + Map[u][v]
                    if alt < dist[v]:
                        dist[v] = alt
                        fa[v] = u
                        heapq.heappush(pq, (dist[v], v))
            
            ret = 0
            for i in range(n):
                if i != source and dist[i] <= thresHold:
                    ret += 1

            return ret        
        
        num = n + 1
        ret = -1
        for i in range(n):
            N = Djikstra(i, distanceThreshold)
            # print(N)
            if num >= N:
                num = N
                ret = i

        return ret
```
