#### 方法一：计算到各节点的最短距离【通过】

**思路和算法**

假设 `pre[node]` 是到经过 `T` 个节点到达目的节点 `node` 的最短距离，然后求解经过 `T+1` 个节点到达目的节点的最短距离。对于每一条连接城市 `u` 和 `v`，成本为 `w`的航线，更新后的最短距离为 `dis[v] = min(dis[v], pre[u] + w)`。

实际上，初始令 `dis = dist[0]` 和 `pre = dist[1]`，在下一步循环迭代 `(i = 1)` 时，可以重复使用 `dis = dist[1]` 和 `pre = dist[0]`，以此类推。

```java [solution1-Java]
class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        int[][] dist = new int[2][n];
        int INF = Integer.MAX_VALUE / 2;
        Arrays.fill(dist[0], INF);
        Arrays.fill(dist[1], INF);
        dist[0][src] = dist[1][src] = 0;

        for (int i = 0; i <= K; ++i)
            for (int[] edge: flights)
                dist[i&1][edge[1]] = Math.min(dist[i&1][edge[1]], dist[~i&1][edge[0]] + edge[2]);

        return dist[K&1][dst] < INF ? dist[K&1][dst] : -1;
    }
}
```

```python [solution1-Python]
class Solution(object):
    def findCheapestPrice(self, n, flights, src, dst, K):
        dist = [[float('inf')] * n for _ in xrange(2)]
        dist[0][src] = dist[1][src] = 0

        for i in xrange(K+1):
            for u, v, w in flights:
                dist[i&1][v] = min(dist[i&1][v], dist[~i&1][u] + w)

        return dist[K&1][dst] if dist[K&1][dst] < float('inf') else -1
```

**复杂度分析**

* 时间复杂度：$O(E * K)$，其中 $E$ 是 `flights` 的长度。

* 空间复杂度：$O(n)$，存储 `dis` 和 `pre`。

#### 方法二：Dijkstra【通过】

**思路**

寻找源到目标的最低花费，Dijkstra 是一个好的算法。

Dijstra 算法的基本思想就是：按照 `cost` 从小到大的顺序扩展所有可能的飞行路线，当城市被添加到 `dst` 时，`dst` 中对应的值就是到达该城市的最低花费。

**算法**

在 Dijkstra 算法中，借助优先级队列持续搜索花费最低的下一个城市。

如果查找到某个城市，它原本的路线成本更低或者中转次数过多，则无需再搜索它。否则，如果搜索到目的城市，那么当前花费就是最低成本，因为每次最先搜索的就是最低成本航线。

否则，如果从 `node` 城市出发的航线花费更低，则将该节点加入到优先级队列用于搜索。

```java [solution2-Java]
class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        int[][] graph = new int[n][n];
        for (int[] flight: flights)
            graph[flight[0]][flight[1]] = flight[2];

        Map<Integer, Integer> best = new HashMap();

        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a, b) -> a[0] - b[0]);
        pq.offer(new int[]{0, 0, src});

        while (!pq.isEmpty()) {
            int[] info = pq.poll();
            int cost = info[0], k = info[1], place = info[2];
            if (k > K+1 || cost > best.getOrDefault(k * 1000 + place, Integer.MAX_VALUE))
                continue;
            if (place == dst)
                return cost;

            for (int nei = 0; nei < n; ++nei) if (graph[place][nei] > 0) {
                int newcost = cost + graph[place][nei];
                if (newcost < best.getOrDefault((k+1) * 1000 + nei, Integer.MAX_VALUE)) {
                    pq.offer(new int[]{newcost, k+1, nei});
                    best.put((k+1) * 1000 + nei, newcost);
                }
            }
        }

        return -1;
    }
}
```

```python [solution2-Python]
class Solution(object):
    def findCheapestPrice(self, n, flights, src, dst, K):
        graph = collections.defaultdict(dict)
        for u, v, w in flights:
            graph[u][v] = w

        best = {}
        pq = [(0, 0, src)]
        while pq:
            cost, k, place = heapq.heappop(pq)
            if k > K+1 or cost > best.get((k, place), float('inf')): continue
            if place == dst: return cost

            for nei, wt in graph[place].iteritems():
                newcost = cost + wt
                if newcost < best.get((k+1, nei), float('inf')):
                    heapq.heappush(pq, (newcost, k+1, nei))
                    best[k+1, nei] = newcost

        return -1
```

**复杂度分析**

* 时间复杂度：$O(E + n \log n)$，其中 $E$ 是航线的数量。

* 空间复杂度：$O(n)$，优先级队列的大小。