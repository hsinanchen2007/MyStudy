最短路径常用的方法之一是广度优先搜索。广度优先搜索的元素包括特定时刻的状态以及可能的操作。
对于这道题，情况较为复杂，需要考虑的状态有蛇尾在每个方格的时候，蛇的朝向即蛇头是向右还是向下，操作则有右移、下移、旋转。
一些状态需要排除，包括障碍物（`grid`数组中等于`1`的位置）和蛇头在网格以外的情况（蛇尾在最右列蛇头向右、蛇尾在最下行蛇头向下）。
搜索过程使用`Queue`，这和常规的广度优先搜索相同。从`Queue`中取出一个状态，其后继状态可能是经过右移、下移、旋转的操作之后得到的状态，对于每种操作，需要判定是否合法，只有合法的状态才能加入到`Queue`中。
当`Queue`变为空的时候，需要得到的状态是：倒数第一行和倒数第二列，蛇头向右的位置。获得该状态的距离，如果距离不为无穷，则返回实际距离，如果距离为无穷，说明这个状态不可达到，返回`-1`。
```
class Solution {
    public int minimumMoves(int[][] grid) {
        final int BLOCK = -1;
        final int WHITE = 0;
        final int GRAY = 1;
        final int BLACK = 2;
        int rows = grid.length, columns = grid[0].length;
        int[][][] colors = new int[rows][columns][2];
        int[][][] distances = new int[rows][columns][2];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                distances[i][j][0] = Integer.MAX_VALUE;
                distances[i][j][1] = Integer.MAX_VALUE;
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] == 1) {
                    colors[i][j][0] = BLOCK;
                    colors[i][j][1] = BLOCK;
                    distances[i][j][0] = -1;
                    distances[i][j][1] = -1;
                    if (i > 0) {
                    	colors[i - 1][j][1] = BLOCK;
                        distances[i - 1][j][1] = -1;
                    }
                    if (j > 0) {
                    	colors[i][j - 1][0] = BLOCK;
                        distances[i][j - 1][0] = -1;
                    }
                }
                if (i == rows - 1) {
                    colors[i][j][1] = BLOCK;
                    distances[i][j][1] = -1;
                }
                if (j == columns - 1) {
                    colors[i][j][0] = BLOCK;
                    distances[i][j][0] = -1;
                }
            }
        }
        distances[0][0][0] = 0;
        Queue<int[]> queue = new LinkedList<int[]>();
        queue.add(new int[]{0, 0, 0});
        while (!queue.isEmpty()) {
            int[] status = queue.poll();
            int row = status[0], column = status[1], direction = status[2];
            int distance = distances[row][column][direction];
            if (row < rows - 1) {
                int rowDown = row + 1;
                if (colors[rowDown][column][direction] == WHITE) {
                    colors[rowDown][column][direction] = GRAY;
                    distances[rowDown][column][direction] = distance + 1;
                    queue.offer(new int[]{rowDown, column, direction});
                }
            }
            if (column < columns - 1) {
                int columnRight = column + 1;
                if (colors[row][columnRight][direction] == WHITE) {
                    colors[row][columnRight][direction] = GRAY;
                    distances[row][columnRight][direction] = distance + 1;
                    queue.offer(new int[]{row, columnRight, direction});
                }
            }
            int newDirection = 1 - direction;
            if (colors[row][column][newDirection] == WHITE && row < rows - 1 && column < columns - 1 && grid[row + 1][column + 1] == 0) {
                colors[row][column][newDirection] = GRAY;
                distances[row][column][newDirection] = distance + 1;
                queue.offer(new int[]{row, column, newDirection});
            }
            colors[row][column][direction] = BLACK;
        }
        int retDistance = distances[rows - 1][columns - 2][0];
        if (retDistance == Integer.MAX_VALUE)
            retDistance = -1;
        return retDistance;
    }
}
```
