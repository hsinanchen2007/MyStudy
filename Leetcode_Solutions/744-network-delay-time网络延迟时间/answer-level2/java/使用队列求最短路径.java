int[][] graph[1...N+1][1...N+1]：使用邻接矩阵存储图结构，初始化为-1，表示节点之间无边。
int[] dist[1...N+1]：记录节点K到其他节点的最短距离(使用队列不断更新这个数组)。初始化为Integet.MAX_VALUE。

首先将源点K加入队列，并更新dist[K]=0;
**对于更新了dist的节点都要加入队列q中9(包括节点K)。这些节点最短距离的变更，可能导致与这些节点的相邻节点的最短距离更新。**
```
    // 72.81% 8ms(中文) 95.34% 8ms(英文)
    public int networkDelayTime(int[][] times, int N, int K) {
        int[][] graph = new int[N+1][N+1];
        for (int i = 1; i < N + 1; i++) {
            for (int j = 1; j < N + 1; j++) {
                graph[i][j] = -1;
            }
        }
        for (int[] edge : times) {
            graph[edge[0]][edge[1]] = edge[2];
        }

        int[] dist = new int[N+1];
        for (int i = 1; i < N+1; i++) {
            dist[i] = Integer.MAX_VALUE;
        }
        dist[K] = 0;
        Queue<Integer> q = new LinkedList<>();
        q.add(K);

        while (!q.isEmpty()) {
            // 更新q中节点到其他节点的距离
            Integer poll = q.poll();
            for (int i = 1; i < N + 1; i++) {
                if (graph[poll][i] == -1) continue;
                if (dist[i] > dist[poll] + graph[poll][i]){
                    dist[i] = Math.min(dist[i], dist[poll]+graph[poll][i]);
                    if (!q.contains(i))
                        q.add(i);
                }
            }
        }
        int res = 0;
        for (int i = 1; i < N+1; i++) {
            if (dist[i] == Integer.MAX_VALUE) return -1;
            res = Math.max(res, dist[i]);

        }
        return res;
    }
```
如果对您有帮助，请给个赞吧^_^