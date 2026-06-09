### 解题思路
这个问题比较清晰，所有的操作都比较容易步骤化，关键在于利用队列实现广度优先遍历。

通过面向对象设计一个类，表示坐标，方法能够获取邻居节点的；

顺着问题操作对象，逐步解决即可。

PS: 效率比较慢。

### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {
        Queue<Point> queueA = new LinkedList<>();
        Queue<Point> queueB = new LinkedList<>();
        int result = 0;
        int fresh = 0;

        // step 1 把所有的烂橘子入队
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++){
                if (grid[i][j] == 2) {
                    queueA.offer(new Point(i, j));
                }
                if (grid[i][j] == 1) {
                    fresh ++;
                }
            }
        }

        // step 2 坐标出队, 感染邻居节点
        while (true) {
            while (!queueA.isEmpty()) {
                Point p = queueA.poll();
                for (Point n : p.neibors()) {
                    if (n.isInGrid(grid) && grid[n.x][n.y] == 1) {
                        queueB.offer(new Point(n.x, n.y));    // 腐烂，且入队
                        grid[n.x][n.y] = 2;
                        fresh --;
                    }
                }
            }
            if (queueB.isEmpty()) {
                break;
            }
            result ++;
            Queue temp = queueA;
            queueA = queueB;
            queueB = temp;
        }

        if (fresh > 0) return -1;
        return result;
    }

    static class Point {

        private int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        /**
         * 获取 邻居 节点坐标
         */
        public Point[] neibors() {
            return new Point[]{
                new Point(x + 1, y),
                new Point(x - 1, y),
                new Point(x, y + 1),
                new Point(x, y - 1)
            };
        }

        public boolean isInGrid(int[][] grid) {
            return this.x >= 0 && this.y >= 0 && this.x < grid.length && this.y < grid[0].length;
        }
    }
}
```