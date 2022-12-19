```
class Solution {
    int[] dx = {-1, 1, 0, 0}; // 方向数组
    int[] dy = {0, 0, -1, 1};

    public int trapRainWater(int[][] heightMap) {
        if (heightMap.length < 3 || heightMap[0].length < 3) {
            return 0;
        }

        int row = heightMap.length;
        int column = heightMap[0].length;
        boolean[][] visit = new boolean[row][column];
        PriorityQueue<QItem> queue = new PriorityQueue<>();
        for (int i = 0; i < row; i++) {
            queue.offer(new QItem(i, 0, heightMap[i][0]));
            visit[i][0] = true;
            queue.offer(new QItem(i, column - 1, heightMap[i][column - 1]));
            visit[i][column - 1] = true;
        }
        for (int i = 1; i < column - 1; i++) {
            queue.offer(new QItem(0, i, heightMap[0][i]));
            visit[0][i] = true;
            queue.offer(new QItem(row - 1, i, heightMap[row - 1][i]));
            visit[row - 1][i] = true;
        }

        return bfs(queue, heightMap, visit);
    }

    public int bfs(PriorityQueue<QItem> queue, int[][] heightMap, boolean[][] visit) {
        int result = 0;
        while (!queue.isEmpty()) {
            QItem top = queue.poll();
            for (int i = 0; i < 4; i++) {
                int newX = dx[i] + top.x;
                int newY = dy[i] + top.y;
                if (newX < 0 || newX >= heightMap.length || newY < 0 || newY >= heightMap[0].length || visit[newX][newY]) {
                    continue;
                }
                if (heightMap[newX][newY] < top.h) {
                    result += top.h - heightMap[newX][newY];
                    heightMap[newX][newY] = top.h;
                }
                queue.offer(new QItem(newX, newY, heightMap[newX][newY]));
                visit[newX][newY] = true;
            }
        }
        
        return result;
    }

    static class QItem implements Comparable<QItem> {
        int x;
        int y;
        int h;
        QItem(int x, int y, int h) {
            this.x = x;
            this.y = y;
            this.h = h;
        }

        public int compareTo(QItem item) {
            return h - item.h;
        }
    }
}
```
