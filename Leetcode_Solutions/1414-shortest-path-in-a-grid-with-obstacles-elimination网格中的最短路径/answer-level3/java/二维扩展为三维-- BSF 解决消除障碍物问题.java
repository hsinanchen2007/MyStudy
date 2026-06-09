### 解题思路
   本题核心逻辑还是BSF，只是对访问记录做了修改，之前记录是x和y（二维）被访问过，现在的记录是x,y,z,把二维的扩展为三维，其中z的取值是【0-k】，表示当前已经消除过多少障碍物。
  ** BSF算法的核心就是访问记录的保存，理解了访问记录的保存方法，就掌握了BSF的核心。**

### 代码

```java
class Solution {
    private int[][] dir = new int[][] {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    public int shortestPath(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        boolean[][][] visited = new boolean[m][n][k + 1];
        Queue<Point> queue = new LinkedList<>();

        queue.add(new Point(0, 0, 0));

        // **核心逻辑**：访问记录二维扩展为三维
        visited[0][0][0] = true;

        int distance = 0;
        while (!queue.isEmpty()) {
            distance++;

            int size = queue.size();

            for (int i = 0; i < size; i++) {

                Point point = queue.poll();

                int x = point.x;
                int y = point.y;
                int z = point.z;

                // 找到障碍物
                if (x == m - 1 && y == n - 1) {
                    return distance -1;
                }

                // 4个方向移动
                for (int j = 0; j < 4; j++) {
                    int newX = x + dir[j][0];
                    int newY = y + dir[j][1];
                    int newZ = z;

                    if (newX < 0 || newX >= m || newY < 0 || newY >= n) {
                        continue;
                    }

                    // **核心逻辑**：有障碍物要对其进行处理，计算是否还能消除障碍物
                    if (grid[newX][newY] == 1) {
                        // 没有消除 k 个障碍物，可以继续消除
                        if (z < k) {
                            newZ = z + 1;
                        } else {
                            // 已经消除 k 个障碍物
                            continue;
                        }
                    }

                    if (!visited[newX][newY][newZ]) {
                        queue.add(new Point(newX, newY, newZ));
                        visited[newX][newY][newZ] = true;
                    }
                }
            }
        }
        return -1;
    }

    class Point {
        int x;

        int y;

        int z;

        public Point(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }
}
```