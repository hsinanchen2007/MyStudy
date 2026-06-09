### 解题思路
在上一个题的基础上要找出最短距离，实际上就是单源最短路，迷宫里每个格子都是一个节点，边权为 1，没有负权边，可以用dijkstra，但我感觉我写的不像啊，我也晕了（新手
，我说的不对麻烦大家帮我指正）用一个二维数组 dist[i][j]表示从起点到这个位置的最短距离（步数），在后面遍历过程中不断的去更新即可

### BFS代码

```java
class Solution {
    public int shortestDistance(int[][] maze, int[] start, int[] dest) {
        int n = maze.length;
        int m = maze[0].length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> o1[2] - o2[2]);
        // 用队列也是可以的
        // Queue<int[]> queue = new LinkedList<>();
        pq.offer(new int[]{start[0], start[1], 0});
        int[][] dist = new int[n][m];
        for (int[] arr : dist) {
            Arrays.fill(arr, Integer.MAX_VALUE);
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!pq.isEmpty()) {
            int[] poll = pq.poll();
            for (int k = 0; k < 4; k++) {
                int x = poll[0], y = poll[1], distance = poll[2];
                while (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0) {
                    x += dirs[k];
                    y += dirs[k + 1];
                    distance++;
                }
                x -= dirs[k];
                y -= dirs[k + 1];
                distance--;
                if (dist[x][y] > distance) {
                    dist[x][y] = distance;
                    pq.offer(new int[]{x, y, distance});
                }
            }
        }
        return dist[dest[0]][dest[1]] == Integer.MAX_VALUE ? -1 : dist[dest[0]][dest[1]];
    }
}
```

### DFS代码
```java
class Solution {
    public int shortestDistance(int[][] maze, int[] start, int[] dest) {
        int n = maze.length;
        int m = maze[0].length;
        int[][] dist = new int[n][m];
        for (int[] arr : dist) {
            Arrays.fill(arr, Integer.MAX_VALUE);
        }
        dist[start[0]][start[1]] = 0;
        helper(maze, start[0], start[1], dist, dest);
        return dist[dest[0]][dest[1]] == Integer.MAX_VALUE ? -1 : dist[dest[0]][dest[1]];
    }

    int[] dirs = {-1, 0, 1, 0, -1};

    private void helper(int[][] maze, int x, int y, int[][] dist, int[] dest) {
        if (x == dest[0] && y == dest[1]) {
            return;
        }
        int n = maze.length;
        int m = maze[0].length;
        for (int k = 0; k < 4; k++) {
            int nx = x, ny = y;
            int distance = dist[nx][ny];
            while (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 0) {
                nx += dirs[k];
                ny += dirs[k + 1];
                distance++;
            }
            nx -= dirs[k];
            ny -= dirs[k + 1];
            distance--;
            if (distance < dist[nx][ny]) {
                dist[nx][ny] = distance;
                helper(maze, nx, ny, dist, dest);
            }
        }
    }
}
```