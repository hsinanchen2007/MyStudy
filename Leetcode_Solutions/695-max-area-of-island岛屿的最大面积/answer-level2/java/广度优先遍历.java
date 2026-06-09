### 解题思路
深度遍历，用一个二维数组维护元素是否被访问过，用一个队列维护元素为1（海岛）的位置，队列不为空就弹出一个元素，小岛面积加一，并以此元素为基础继续往四个方向探索，满足条件的进入队列，直到队列为空，说明本次探索结束 记录下小岛面积

注意：元素进入队列后 visited 一定立马做标记，防止该元素后面重复进入

### 代码

```java
class Solution {
  public int maxAreaOfIsland(int[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0) {
            return 0;
        }

        int rows = grid.length;
        int columns = grid[0].length;
        boolean[][] visited = new boolean[rows][columns];
        int[][] dxy = new int[][] {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        List<Integer> record = new ArrayList<>();
        Queue<Point> queue = new LinkedList<>();
        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    count = 0;
                    queue.add(new Point(i, j));
                    visited[i][j] = true;
                    while (!queue.isEmpty()) {
                        Point point = queue.poll();
                        count++;
                        for (int[] ints : dxy) {
                            int x = point.x + ints[0];
                            int y = point.y + ints[1];
                            if (x < 0 || x >= rows || y < 0 || y >= columns) {
                                continue;
                            }

                            if (visited[x][y]) {
                                continue;
                            }

                            if (grid[x][y] == 1) {
                                queue.add(new Point(x, y));
                                visited[x][y] = true;
                            }
                        }
                    }

                    record.add(count);
                }
            }
        }

        if (record.size() <= 0) {
            return 0;
        }

        record.sort(Comparator.reverseOrder());

        return record.get(0);
    }

    static class Point {
        int x;

        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
```