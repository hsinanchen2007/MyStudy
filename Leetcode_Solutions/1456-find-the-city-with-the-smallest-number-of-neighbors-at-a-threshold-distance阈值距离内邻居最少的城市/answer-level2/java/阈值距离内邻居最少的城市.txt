### 解题思路
dijkstra算法,求出到各个点的最短路径,找出能在距离阈值范围之内的点最少的那个

### 代码

```java
class Solution {
    private int []vis;
    private int[][] map;
    private int ans, min = Integer.MAX_VALUE;
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        map = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.MAX_VALUE;
            }
        }
        for (int[] edge : edges) {
            int v = edge[0];
            int e = edge[1];
            int w = edge[2];
            map[v][e] = w;
            map[e][v] = w;
        }
        for (int i = 0; i < n; i++) {
            dijkstra(i, n, distanceThreshold);
        }
        return ans;
    }

    public void dijkstra(int v0, int n, int distanceThreshold) {
        boolean[] s = new boolean[n];
        int []dist = new int[n];
        for (int i = 0; i < n; i++) {
            s[i] = false;
            dist[i] = map[v0][i];
        }
        dist[v0] = 0;
        s[v0] = true;
        int v = 0;
        for (int i = 1; i < n - 1; i++) {
            int min = Integer.MAX_VALUE;
            for (int w = 0; w < n; w++) {
                if (!s[w] && dist[w] < min) {
                    v = w;
                    min = dist[w];
                }
            }
            s[v] = true;
            for (int j = 0; j < n; j++) {
                if (!s[j] && (min + map[v][j] < dist[j]) && map[v][j] != Integer.MAX_VALUE) {
                    dist[j] = min + map[v][j];
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < dist.length; i++) {
            if (dist[i] != 0 && dist[i] <= distanceThreshold) {
                cnt++;
            }
        }
        if (min >= cnt) {
            min = cnt;
            ans = v0;
        }
    }
}
```