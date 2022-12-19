### 解题思路
这题最朴素最容易想到的就是BFS了，完全就是一道BFS裸题。从原点出发，沿四个方向（**其实两个方向就行了，因为可行区域在原点的右上方**）不断拓展，将可到达并且满足坐标数位和不大于`k`的点加入到队列中，直到所有可到达的点都被访问到。

### 代码

```java
class Solution {
    public int movingCount(int m, int n, int k) {
        int res = 1;

        // 向右上方移动
        int[][] move = new int[][] {{1, 0}, {0, 1}};
        // 记录某个位置是否访问过
        boolean[][] visit = new boolean[m][n];
        // 维护可到达的点队列        
        Queue<Point> queue = new LinkedList<>();
        queue.offer(new Point(0, 0));
        visit[0][0] = true;

        while (!queue.isEmpty()) {
            Point currPoint = queue.poll();
            for (int i = 0; i < move.length; i++) {
                int nextX = currPoint.x + move[i][0];
                int nextY = currPoint.y + move[i][1];
                if (check(nextX, nextY, m, n, k, visit)) {
                    queue.offer(new Point(nextX, nextY));
                    visit[nextX][nextY] = true;
                    res++;
                }
            }
        }

        return res;
    }

    // 判断某个位置是否合法
    private boolean check(int x, int y, int m, int n, int k, boolean[][] visit) {
        if (x >= 0 && x < m && y >= 0 && y < n && !visit[x][y] && getNumericalDigit(x) + getNumericalDigit(y) <= k) {
            return true;
        }
        return false;
    }

    // 获取一个整数的数位和
    private int getNumericalDigit(int num) {
        int res = 0;
        while (num > 0) {
            res += num % 10;
            num /= 10;
        }
        return res;
    }
}

// 坐标对象类
class Point {
    int x;
    int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
```

当然，这道题用dfs也很简单。

```java
class Solution {
    public int movingCount(int m, int n, int k) {
        boolean[][] visited = new boolean[m][n];
        return dfs(0, 0, m, n, k, visited);
    }

    private int dfs(int x, int y, int m, int n, int k, boolean[][] visited) {
        if (x == m || y == n || getNumericalDigit(x) + getNumericalDigit(y) > k || visited[x][y]) {
            return 0;
        }
        visited[x][y] = true;
        // 可行区域在原点的右上方，所以只向右和向上拓展就行了
        return 1 + dfs(x + 1, y, m, n, k, visited) + dfs(x, y + 1, m, n, k, visited);
    }

    // 获取一个整数的数位和
    private int getNumericalDigit(int num) {
        int res = 0;
        while (num > 0) {
            res += num % 10;
            num /= 10;
        }
        return res;
    }
}
```