关键：如何连接岛的过程，获取最小的数量
```
class Solution {
    int[] dx = new int[] {0, 1, 0, -1};
    int[] dy = new int[] {1, 0, -1, 0}; // 4个方向

    public int shortestBridge(int[][] A) {
        int r = A.length;
        int c = A[0].length;
        int[][] visit = new int[r][c];
        int mark = 0; // 代表岛的id
        
        // 首先深度遍历2个岛的位置
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (visit[i][j] == 0 && A[i][j] == 1) {
                    mark++;
                    // dfs(A, visit, i, j, mark); // 深度
                    bfs(A, visit, i, j, mark); // 广度
                }
            }
        }
        
        // 选取一个岛，将其位置都放进队列，对这个队列进行bfs；将另一个岛的位置同时存储起来
        Queue<QItem> queue = new LinkedList<>(); // 存储岛1
        Set<Integer> set = new HashSet<>(); // 存储岛2
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (visit[i][j] == 1) { // 岛1
                    queue.offer(new QItem(i, j, 0));
                } else if (visit[i][j] == 2) {
                    set.add(i * c + j); // 保存岛2位置，这样方便后续判断是否已经存在，而不是通过对象保存
                }
            }
        }
        //System.out.println(queue);
        //System.out.println(set);
        return bfs_connect(visit, queue, set);
    }

    // 广度查找岛的位置
    public void bfs(int[][] A, int[][] visit, int x, int y, int mark) {
        Queue<QItem> queue = new LinkedList<>();
        queue.offer(new QItem(x, y, 0));
        visit[x][y] = mark;
        while (!queue.isEmpty()) {
            QItem top = queue.poll();
            for (int i = 0; i < 4; i++) {
                int newX = top.x + dx[i];
                int newY = top.y + dy[i];
                if (newX < 0 || newX >= visit.length || newY < 0 || newY >= visit.length || visit[newX][newY] != 0) {
                    continue;
                }
                if (A[newX][newY] == 1) {
                    queue.offer(new QItem(newX, newY, 0));
                    visit[newX][newY] = mark;
                }
            }
        }
    }

    // 深度查找岛的位置
    public void dfs(int[][] A, int[][] visit, int x, int y, int mark) {
        if (x < 0 || x >= A.length || y < 0 || y >= A.length || visit[x][y] != 0) {
            return;
        }
        if (A[x][y] == 1) {
            visit[x][y] = mark;
            for (int i = 0; i < 4; i++) {
                dfs(A, visit, x + dx[i], y + dy[i], mark);
            }
        }
    }

    // 广度连接2个岛
    public int bfs_connect(int[][] visit, Queue<QItem> queue, Set<Integer> set) {
        while (!queue.isEmpty()) {
            QItem top = queue.poll();
            if (set.contains(top.x * visit[0].length + top.y)) {
                return top.depth - 1;
            }
            for (int i = 0; i < 4; i++) {
                int newX = top.x + dx[i];
                int newY = top.y + dy[i];
                if (newX < 0 || newX >= visit.length || newY < 0 || newY >= visit.length || visit[newX][newY] == 1) {
                    continue;
                } else {
                    queue.offer(new QItem(newX, newY, top.depth + 1));
                    visit[newX][newY] = 1;
                }
            }
        }
        throw null;
    }

    static class QItem {
        int x;
        int y;
        int depth; // 表示岛中“1”的外围层数
        QItem(int x, int y, int depth) {
            this.x = x;
            this.y = y;
            this.depth = depth;
        }
        public String toString() {
           return "[" + x + ", " + y + ", " + depth + "]";
        }
    }
}
```
