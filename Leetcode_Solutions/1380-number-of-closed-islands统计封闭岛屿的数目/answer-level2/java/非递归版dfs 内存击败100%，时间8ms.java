### 解题思路
思路：孤岛里面的区域肯定不会挨着边缘，如果挨着边缘说明非孤岛。
算法：从每个0开始深度遍历，当遍历遇到边缘时，说明这个陆地区域非孤岛，否则孤岛数+1，用visited[][]记录访问的点，避免重复访问。

### 代码

```java
class Solution {
public int closedIsland(int[][] grid) {
        if (grid == null || grid.length <= 1 || grid[0].length <= 1) {
            return 0;
        }
        int rows = grid.length;
        int cols = grid[0].length;

        boolean[][] visited = new boolean[rows][cols];

        int num = 0;
        for (int i = 1; i < rows - 1; i++) {
            for (int j = 1; j < cols - 1; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    if (isIsland(grid, i, j, visited)) {
                        num++;
                    }
                }
            }
        }

        return num;
    }

    private boolean isIsland(int[][] grid, int row, int col, boolean[][] visited) {
        int rows = grid.length;
        int cols = grid[0].length;
        Stack<Point> stack = new Stack<>();
        stack.add(new Point(row, col));
        boolean isIsland = true;
        while (!stack.isEmpty()) {
            Point p = stack.pop();
            visited[p.i][p.j] = true;
            int i = p.i;
            int j = p.j;
            if ((i - 1 >= 0) && grid[i - 1][j] == 0 && visited[i - 1][j] == false) {
                if (isEdge(i - 1, j, rows, cols)) {
                    isIsland = false;
                }
                stack.push(new Point(i - 1, j));
            }
            if ((j - 1 >= 0) && grid[i][j - 1] == 0 && visited[i][j - 1] == false) {
                if (isEdge(i, j - 1, rows, cols)) {
                    isIsland = false;
                }
                stack.push(new Point(i, j - 1));
            }
            if ((i + 1 < rows) && grid[i + 1][j] == 0 && visited[i + 1][j] == false) {
                if (isEdge(i + 1, j, rows, cols)) {
                    isIsland = false;
                }
                stack.push(new Point(i + 1, j));
            }
            if ((j + 1 < cols) && grid[i][j + 1] == 0 && visited[i][j + 1] == false) {
                if (isEdge(i, j + 1, rows, cols)) {
                    isIsland = false;
                }
                stack.push(new Point(i, j + 1));
            }
        }
        return isIsland;
    }

    private boolean isEdge(int i, int j, int rows, int cols) {
        if (i <= 0 || j <= 0 || i >= rows - 1 || j >= cols - 1) {
            return true;
        }
        return false;
    }

    private class Point {
        int i;
        int j;
        public Point(int i, int j) {
            this.i = i;
            this.j = j;
        }
    }
}
```