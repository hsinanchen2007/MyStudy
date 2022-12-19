### 解题方案
- 基于队列的广度优先BFS
- 基于回溯思想和递归的深度优先DFS

### 方案选择
- BFS比较直观，符合直觉
- DFS用到回溯的思想，解法精巧
- 两种思路不同，分别讨论实现

### BFS解题思路
1. 所有腐烂橘子（起点）入队，记录新鲜橘子总数
2. 依照层序，迭代处理各层各顶点
    - 当前层顶点出队
    - 传染上下左右相邻顶点
    - 被传染顶点入队 
3. 判断是否有遗漏橘子

#### BFS代码实现
```java

class Point {
    int row;
    int col;
    public Point(int row, int col) {
        this.row = row;
        this.col = col;
    }
}
public int orangesRotting(int[][] grid) {
        Queue<Point> queue = new LinkedList<>();
        int numOfFresh = 0;

        // traverse grid, enqueue rotten, count num of fresh
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                int curr = grid[i][j];
                if (curr == 2) {
                    queue.add(new Point(i, j));
                } else if (curr == 1) {
                    numOfFresh++;
                }
            }
        }

        if (numOfFresh == 0) {
            return 0;
        }

        // down, up, right, left
        int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int turn = 0;
        while (!queue.isEmpty()) {
            turn++;
            int numOfRotten = queue.size();
            for (int i = 0; i < numOfRotten; i++) {
                Point curr = queue.poll();
                // 4 directions
                for (int[] direction : directions) {
                    int row = curr.row + direction[0];
                    int col = curr.col + direction[1];
                    if (row < 0 || col < 0
                            || row >= grid.length
                            || col >= grid[0].length
                            || grid[row][col] != 1) {
                        continue;
                    }
                    grid[row][col] = 2;
                    queue.add(new Point(row, col));
                    numOfFresh--;
                }
            }
        }

        return (numOfFresh == 0) ? (turn - 1) : -1;
    }

```

### DFS解题思路

#### 问题抽象化
```
求所有水果被腐烂的最短时间
         V
每个水果有一个被腐烂的最短时间，取数值最大的时间
         V
图中每个顶点有一个到达最近起点的最短路径，取数值最大的路径
```

#### 步骤详解
1. 第一次遍历得到每个顶点到达最近起点的最短路径
```text
0 1 2      0 3 2
2 1 1  =>  2 3 3 
1 0 1      3 0 4
```
2. 第二次遍历取最大数值，判断是否有不可达的顶点

#### DFS代码实现

```java
class Solution {
    int[][] grid;
    int numRow;
    int numCol;

    public int orangesRotting(int[][] grid) {
        this.grid = grid;
        this.numRow = grid.length;
        this.numCol = grid[0].length;

        for (int i = 0; i < numRow; i++) {
            for (int j = 0; j < numCol; j++) {
                if (grid[i][j] == 2) {
                    dfs(i, j, 2);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < numRow; i++) {
            for (int j = 0; j < numCol; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
                res = Math.max(res, grid[i][j]);
            }
        }

        return (res == 0) ? 0 : (res - 2);
    }

    private void dfs(int i, int j, int val) {
        grid[i][j] = val;
        // up, left, down, right
        int[][] directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        for (int[] dir : directions) {
            // recursively tracing 4 directions
            if (isReachable(i, j, dir)) {
                dfs(i + dir[0], j + dir[1], val + 1);
            }
        }
    }

    private boolean isReachable(int i, int j, int[] direction) {
        int row = i + direction[0];
        int col = j + direction[1];
        if (row < 0 || col < 0 || row >= numRow || col >= numCol) {
            return false;
        }

        int target = grid[row][col];
        return target == 1 || target > grid[i][j] + 1;
    }
}
```

### Repo
[Github Repo](https://github.com/muscaestar/myDailyLeetCode/tree/master/src/_994_Rotting_Oranges)