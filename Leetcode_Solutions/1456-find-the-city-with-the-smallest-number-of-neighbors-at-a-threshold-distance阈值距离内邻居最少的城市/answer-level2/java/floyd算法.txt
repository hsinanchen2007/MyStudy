```
class Solution {
    final int INF = 100000000;
    int[][] graph;
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        graph = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = INF;
            }
        }
        for (int i = 0; i < n; i++) {
            graph[i][i] = 0;
        }
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            graph[u][v] = weight;
            graph[v][u] = weight;
        }
        floyd(n);
        int min = INF;
        int minIndex = -1;
        for (int i = graph.length - 1; i >= 0; i--) {
            int count = 0;
            for (int j : graph[i]) {
                if (j <= distanceThreshold) {
                    count++;
                }
            }
            if (count < min) {
                min = count;
                minIndex = i;
            }
        }
        return minIndex;
    }

    void floyd(int n) {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (graph[i][k] != INF && graph[k][j] != INF
                            && graph[i][k] + graph[k][j] < graph[i][j]) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }
}
```
