求最大的最短路径。

这是我的[LeetCode分类题解](https://github.com/caipengbo/LeetCode)（每日更新, issue内有总结），和我一起每日刷题吧！

以下是Dijkstra算法（未使用堆优化）。
```Java
public int networkDelayTime(int[][] times, int N, int K) {
    // 构建邻接矩阵
    int[][] graph = new int[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            graph[i][j] = -1;
        }
    }
    for (int i = 0; i < times.length; i++) {
        graph[times[i][0]-1][times[i][1]-1] = times[i][2];  // 注意下标从0开始
    }
    return dijkstra(graph, N, K-1);
}
// 寻找连接的最小的点，不存在，返回 -1；
private int findMinVertex(int[] distance, boolean[] visited) {
    int minValue = Integer.MAX_VALUE, minVertex = -1;
    for (int i = 0; i < distance.length; i++) {
        if (!visited[i] && distance[i] < minValue) {
            minValue = distance[i];
            minVertex = i;
        }
    }
    return minVertex;
}
public int dijkstra(int[][] graph, int N, int src) {
    int[] distance = new int[N];
    boolean[] visited = new boolean[N];
    HashMap<Integer, Integer> retMap = new HashMap<>();
    int ret = -1;
    for (int i = 0; i < N; i++) {
        if (graph[src][i] != -1) distance[i] = graph[src][i];
        else distance[i] = Integer.MAX_VALUE;
    }
    visited[src] = true;
    for (int i = 0; i < N-1; i++) {
        int minVertex = findMinVertex(distance, visited);
        if (minVertex == -1) return -1;  // 有无法抵达的点
        visited[minVertex] = true;
        retMap.put(minVertex, distance[minVertex]);
        ret = Math.max(ret, distance[minVertex]);  // 更新最大
        // 更新 distance
        for (int j = 0; j < N; j++) {
            if (graph[minVertex][j] != -1 && !visited[j] && distance[minVertex]+graph[minVertex][j] < distance[j]) {
                distance[j] = distance[minVertex] + graph[minVertex][j];
            }
        }
    }
    // System.out.println(retMap.toString());
    return ret;
}
```
