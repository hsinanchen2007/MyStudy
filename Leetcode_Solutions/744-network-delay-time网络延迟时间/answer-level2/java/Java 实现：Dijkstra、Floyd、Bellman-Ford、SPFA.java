1.Dijkstra 算法
![Dijkstra.png](https://pic.leetcode-cn.com/6bb9b8a3d2b31a8a9ca10b0aa3b669585b33e207765e3fa59ff4f0fabb8d60c1-Dijkstra.png)

```
class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
        // 构建邻接表，用于存放各个点到各个点的距离
        int[][] graph = new int[N + 1][N + 1];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                graph[i][j] = -1;
            }
        }
        // 遍历times填充邻接表
        for (int[] time : times) {
            graph[time[0]][time[1]] = time[2];
        }

        // 存放 K 到各个点的最短路径，最大的那个最短路径即为结果
        int[] distance = new int[N + 1];
        Arrays.fill(distance, -1);

        // 初始化 distance 为 K 到各个节点的距离
        for (int i = 1; i <= N; i++) {
            distance[i] = graph[K][i];
        }
        // K到达K本身的节点初始化为 0
        distance[K] = 0;

        // 判断是否找到K到达该点最短路径
        boolean[] visited = new boolean[N + 1];
        visited[K] = true;

        // 遍历除K本身节点之外的所有N-1个节点
        for (int i = 1; i <= N - 1; i++) {
            int minDistance = Integer.MAX_VALUE;
            int minIndex = 1;
            // 遍历所有节点，找到离K最近的节点
            for (int j = 1; j <= N; j++) {
                if (!visited[j] && distance[j] != -1 && distance[j] < minDistance) {
                    minDistance = distance[j];
                    minIndex = j;
                }
            }

            // 标记最近距离节点找到
            visited[minIndex] = true;

            // 根据刚刚找到的最短距离节点，通过该节点更新K节点与其他的节点的距离
            for (int j = 1; j <= N; j++) {
                // 如果已更新的最短节点可以到达当前节点
                if (graph[minIndex][j] != -1) {
                    if (distance[j] != -1) {
                        // 取之前路径与当前更新路径的最小值
                        distance[j] = Math.min(distance[j], distance[minIndex] + graph[minIndex][j]);
                    } else {
                        // 该节点是第一次访问，直接更新
                        distance[j] = distance[minIndex] + graph[minIndex][j];
                    }
                }
            }
        }

        int maxDistance = 0;
        // 遍历最大值，如果有节点未被访问，返回 -1，否则返回最大最短路径
        for (int i = 1; i <= N; i++) {
            if (distance[i] == -1) {
                return -1;
            }
            maxDistance = Math.max(distance[i], maxDistance);
        }

        return maxDistance;
    }
}
```
2.Floyd 算法
![Floyd.png](https://pic.leetcode-cn.com/b62dbdcc38b8906bec50f9863f0970ef7dd91bbc1a55829e681ddb14f80bab41-Floyd.png)

```
class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
        // 构建邻接表，用于存放各个点到各个点的距离
        int[][] graph = new int[N + 1][N + 1];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                graph[i][j] = i == j ? 0 : -1;
            }
        }
        // 遍历times填充邻接表
        for (int[] time : times) {
            graph[time[0]][time[1]] = time[2];
        }

        // 遍历所有节点，k 表示使用k节点进行松弛
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    // 使用 k 松弛 i->j 的最短路径
                    if (graph[i][k] != -1 && graph[k][j] != -1) {
                        if (graph[i][j] != -1) {
                            graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);
                        } else {
                            graph[i][j] = graph[i][k] + graph[k][j];
                        }
                    }
                }
            }
        }

        int maxDistance = 0;
        // 遍历 K 到所有节点的最短路径的最大值
        for (int i = 1; i <= N; i++) {
            if (graph[K][i] == -1) {
                return -1;
            }
            maxDistance = Math.max(maxDistance, graph[K][i]);
        }
        return maxDistance;
    }
}
```
3.Bellman-Ford 算法
![Bellman-Ford.png](https://pic.leetcode-cn.com/3e58f3cc9c0464a7c65bb9df535866cba2866b120861f2a7eebe6e9c4008b58c-Bellman-Ford.png)

```
class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
        // 存放 K 到各个点的最短路径，最大的那个最短路径即为结果
        int[] distance = new int[N + 1];
        Arrays.fill(distance, -1);
        distance[K] = 0;

        // 进行 N-1 轮的松弛，因为任意两点间的最短路径最多包含 N-1 条边
        for (int i = 1; i <= N - 1; i++) {
            for (int[] time : times) {
                // 源节点
                int u = time[0];
                // 目标节点
                int v = time[1];
                // 一个信号源从源节点到目标节点的时间
                int w = time[2];
                // 判断能否通过 u->v 缩短 distance[v]（松弛）
                if (distance[u] != -1) {
                    if (distance[v] == -1) {
                        distance[v] = distance[u] + w;
                    } else {
                        distance[v] = Math.min(distance[v], distance[u] + w);
                    }
                }
            }
        }

        int maxDistance = 0;
        for (int i = 1; i <= N; i++) {
            if (distance[i] == -1) {
                return -1;
            }
            maxDistance = Math.max(distance[i], maxDistance);
        }

        return maxDistance;
    }
}
```

4.SPFA 算法（队列优化的Bellman-Ford）
![SPFA .png](https://pic.leetcode-cn.com/1f7f3fa85700828bf77d18c102fbc3523d49d2634c93bc8566ffafccd857b893-SPFA%20.png)

```
class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
        // 构建邻接表，用于存放各个点到各个点的距离
        int[][] graph = new int[N + 1][N + 1];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                graph[i][j] = i == j ? 0 : -1;
            }
        }
        // 遍历times填充邻接表
        for (int[] time : times) {
            graph[time[0]][time[1]] = time[2];
        }

        // 存放 K 到各个点的最短路径，最大的那个最短路径即为结果
        int[] distance = new int[N + 1];
        Arrays.fill(distance, -1);
        distance[K] = 0;

        Queue<Integer> queue = new LinkedList<>();
        queue.add(K);

        while (!queue.isEmpty()) {
            // 取出队首节点
            int curr = queue.poll();
            for (int i = 1; i <= N; i++) {
                if (graph[curr][i] != -1 && (distance[i] == -1 || distance[i] > distance[curr] + graph[curr][i])) {
                    // 当最短距离发生变化且不在队列中时，将该节点加入队列
                    distance[i] = distance[curr] + graph[curr][i];
                    if (!queue.contains(i)) {
                        queue.add(i);
                    }
                }
            }
        }

        int maxDistance = 0;
        for (int i = 1; i <= N; i++) {
            if (distance[i] == -1) {
                return -1;
            }
            maxDistance = Math.max(distance[i], maxDistance);
        }

        return maxDistance;
    }
}
```

参考文章：[看完就懂了！一篇搞定图论最短路径问题](https://www.cnblogs.com/thousfeet/p/9229395.html)
Leetcode Github：[Leetcode](https://github.com/hncboy/LeetCode)