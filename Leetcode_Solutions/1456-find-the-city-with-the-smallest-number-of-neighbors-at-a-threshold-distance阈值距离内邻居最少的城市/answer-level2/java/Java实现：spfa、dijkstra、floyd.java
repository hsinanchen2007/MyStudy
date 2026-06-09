### 解题思路
套板子
- 单源最短路
    - 非负权边：$Dijkstra --O(N^2)$,可用堆优化至$O(mlogN)$
    - 带负权边：$Bellman Ford--O(mn)$、升级版$SPFA$
- 多源选最短路
    - $Floyd--O(N^3)$

### 代码
SPFA
```java
class Solution {
    
    int[][] map;
    int[] dist;
    boolean[] set;
    Queue<Integer> queue;

    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        map = new int[n][n];
        for (int[] e : edges) {
            map[e[0]][e[1]] = map[e[1]][e[0]] = e[2];
        }
        int min = n + 1;
        int res = 0;
        for (int i = 0; i < n; i++) {
            int temp = bfs(i, distanceThreshold, n);
            if (temp <= min) {
                min = temp;
                res = i;
            }
        }
        return res;
    }


    //s = start
    private int bfs(int s, int distanceThreshold, int n) {
        queue = new LinkedList<>();
        dist = new int[n];
        set = new boolean[n];
        Arrays.fill(dist, -1);
        Arrays.fill(set, false);

        dist[s] = 0;
        set[s] = true;
        queue.offer(s);

        //SPFA
        while (!queue.isEmpty()) {
            Integer v1= queue.poll();
            for (int v2 = 0; v2 < map[v1].length; v2++) {
                if (map[v1][v2] != 0) {
                    int w = map[v1][v2];
                    if (dist[v2] == -1 || dist[v2] > dist[v1] + w) {
                        dist[v2] = dist[v1] + w;
                        if (!set[v2]) {
                            set[v2] = true;
                            queue.offer(v2);
                        }
                    }
                }
            }
            set[v1] = false;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] == -1) {
                continue;
            }
            if (dist[i] <= distanceThreshold) {
                res++;
            }
        }

        for (int i = 0; i < dist.length; i++) {
            System.out.print(dist[i]+" ");
        }
        System.out.println();
        return res;
    }
}
```
dijkstra
```java
public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        int[][] map = new int[n][n];
        final int INF = 0x3f3f3f3f;
        //init map
        for (int[] ints : map) {
            Arrays.fill(ints, INF);
        }
        for (int i = 0; i < n; i++) {
            map[i][i] = 0;
        }
        for (int[] e : edges) {
            map[e[0]][e[1]] = map[e[1]][e[0]] = e[2];
        }
        int res = 0;
        int MIN = n + 1;

        for (int i = 0; i < n; i++) {
            int[] dist = new int[n];
            boolean[] set = new boolean[n];
            for (int v = 0; v < n; v++) {
                dist[v] = map[i][v];
            }
            dist[i] = 0;
            set[i] = true;
            for (int j = 0; j < n - 1; j++) {
                int min = INF;
                int start = i;
                for (int k = 0; k < n; k++) {
                    if (!set[k] && dist[k] < min) {
                        min = dist[k];
                        start = k;
                    }
                }
                set[start] = true;
                for (int k = 0; k < n; k++) {
                    if (!set[k] && dist[k] > dist[start] + map[start][k]) {
                        dist[k] = dist[start] + map[start][k];
                    }
                }
            }
            int temp = 0;
            for (int j = 0; j < dist.length; j++) {
                if (dist[j] <= distanceThreshold) {
                    temp++;
                }
            }
            if (temp <= MIN) {
                MIN = temp;
                res = i;
            }
        }
        return res;
    }

```

floyd
```java
public static int findTheCity(int n, int[][] edges, int distanceThreshold) {
        int[][] map = new int[n][n];

        //init
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    map[i][j] = 0;
                } else {
                    map[i][j] = Integer.MAX_VALUE;
                }
            }
        }
        //get map 
        for (int[] e : edges) {
            map[e[0]][e[1]] = map[e[1]][e[0]] = e[2];
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i != k && j != k && map[i][k] != Integer.MAX_VALUE && map[k][j] != Integer.MAX_VALUE) {
                        map[i][j] = Math.min(map[i][j], map[i][k] + map[k][j]);
                    }
                }
            }
        }

        //get res
        int min = n + 1;
        int res = -1;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && map[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (min >= count) {
                min = count;
                res = i;
            }
        }
        return res;
    }

```