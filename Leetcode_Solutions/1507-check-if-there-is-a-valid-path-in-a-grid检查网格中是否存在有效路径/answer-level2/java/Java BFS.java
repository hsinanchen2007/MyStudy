比赛时的代码没优化

```
public boolean hasValidPath(int[][] grid) {
    int m = grid.length;
    int n = grid[0].length;
    boolean[][] inQueue = new boolean[m][n];
    Queue<Point> queue = new ArrayDeque<>();
    queue.offer(new Point(0, 0));
    inQueue[0][0] = true;
    while (!queue.isEmpty()) {
        Point head = queue.remove();
        int x = head.x;
        int y = head.y;
        if (x == m - 1 && y == n - 1) {
            return true;
        }
        if (x > 0 && !inQueue[x - 1][y] && isValid(grid[x][y], grid[x - 1][y], "up")) {
            queue.offer(new Point(x - 1, y));
            inQueue[x - 1][y] = true;
        }
        if (x < m - 1 && !inQueue[x + 1][y] && isValid(grid[x][y], grid[x + 1][y], "down")) {
            queue.offer(new Point(x + 1, y));
            inQueue[x + 1][y] = true;
        }
        if (y > 0 && !inQueue[x][y - 1] && isValid(grid[x][y], grid[x][y - 1], "left")) {
            queue.offer(new Point(x, y - 1));
            inQueue[x][y - 1] = true;
        }
        if (y < n - 1 && !inQueue[x][y + 1] && isValid(grid[x][y], grid[x][y + 1], "right")) {
            queue.offer(new Point(x, y + 1));
            inQueue[x][y + 1] = true;
        }
    }
    return false;
}

//是否能从a按照方向dir走到b
boolean isValid(int a, int b, String dir) {
    if (a == 1) {
        if (dir == "left") {
            return b == 1 || b == 4;
        }
        if (dir == "right") {
            return b == 1 || b == 3 || b == 5;
        }
    } else if (a == 2) {
        if (dir == "up") {
            return b == 2 || b == 3 || b == 4;
        }
        if (dir == "down") {
            return b == 2 || b == 5 || b == 6;
        }
    } else if (a == 3) {
        if (dir == "left") {
            return b == 1 || b == 4 || b == 6;
        }
        if (dir == "down") {
            return b == 2 || b == 5 || b == 6;
        }
    } else if (a == 4) {
        if (dir == "right") {
            return b == 1 || b == 3 || b == 5;
        }
        if (dir == "down") {
            return b == 2 || b == 5 || b == 6;
        }
    } else if (a == 5) {
        if (dir == "left") {
            return b == 1 || b == 4 || b == 6;
        }
        if (dir == "up") {
            return b == 2 || b == 3 || b == 4;
        }
    } else if (a == 6) {
        if (dir == "right") {
            return b == 1 || b == 3 || b == 5;
        }
        if (dir == "up") {
            return b == 2 || b == 3 || b == 4;
        }
    }
    return false;
}

class Point {
    int x;
    int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
```
