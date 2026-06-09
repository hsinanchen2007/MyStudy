### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private Queue<Node> q;
    private boolean[][] visited;
    private int maxDistance;

    public Solution() {
        this.q = new LinkedList<Node>();
        this.maxDistance = -1;
    }

    private void InitVisited(int[][] grid) {
        for (int i = 0; i < grid.length; i++) {
            Arrays.fill(this.visited[i], false);
        }
    }

    public int maxDistance(int[][] grid) {
        this.visited = new boolean[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 0) {
                    this.maxDistance = Math.max(bfs(grid, new Node(i, j, 0)), this.maxDistance);
                }
            }
        }
        return this.maxDistance;
    }

    private int bfs(int[][] grid, Node n) {
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        this.InitVisited(grid);
        this.q.clear();
        q.add(n);
        this.visited[n.x][n.y] = true;
        while (this.q.size() != 0) {
            Node cur = this.q.poll();
            for (int i = 0; i < 4; i++) {
                int nextX = cur.x + dx[i];
                int nextY = cur.y + dy[i];
                if (nextX >= 0 && nextX < grid.length && nextY >= 0 && nextY < grid[0].length) {
                    if (this.visited[nextX][nextY]) {
                        continue;
                    }
                    if (grid[nextX][nextY] == 1) {
                        return cur.step + 1;
                    }
                    this.visited[nextX][nextY] = true;
                    q.add(new Node(nextX, nextY, cur.step + 1));
                }
            }
        }
        return -1;
    }

    class Node {
        int x;
        int y;
        int step;
        public Node(int x, int y, int step) {
            this.x = x;
            this.y = y;
            this.step = step;
        }
    }
}
```