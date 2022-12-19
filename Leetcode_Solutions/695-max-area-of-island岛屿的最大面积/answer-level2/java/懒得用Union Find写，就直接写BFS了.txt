### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int max = 0;
        if(grid == null || grid.length == 0 || grid[0] == null || grid[0].length == 0) {
            return max;
        }

        Queue<Point> queue = new LinkedList<>();
        int m = grid.length;
        int n = grid[0].length;
        boolean[][] visited = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int res = bfs(grid, visited, i, j, queue);

                    max = Math.max(max, res);
                }
            }
        }

        return max;
    }

    private int bfs(int[][] grid, boolean[][] visited, int i, int j, Queue<Point> queue) {
        int m = grid.length;
        int n = grid[0].length;

        queue.add(new Point(i, j));
        visited[i][j] = true;
        
        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, -1, 0, 1};
        
        int res = 0;

        while(!queue.isEmpty()) {
            res++;
            Point poll = queue.poll();

            for (int k = 0; k < 4; k++) {
                int nx = poll.x + dx[k];
                int ny = poll.y + dy[k];
                if(isVaild(nx, ny, m, n) && grid[nx][ny] == 1 && !visited[nx][ny]){
                    queue.add(new Point(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
        
        return res;
    }

    private boolean isVaild(int nx, int ny, int m, int n) {
        return nx >= 0 && nx < m && ny >= 0 && ny < n;
    }
}

class Point {
    int x;
    int y;

    Point() {
        x = 0;
        y = 0;
    }

    Point(int a, int b) {
        x = a;
        y = b;
    }
}
```