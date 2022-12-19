```
public char[][] updateBoard(char[][] board, int[] click) {
    int clickX = click[0];
    int clickY = click[1];
    //遇到地雷
    if (board[clickX][clickY] == 'M') {
        board[clickX][clickY] = 'X';
        return board;
    }
    int m = board.length;
    int n = board[0].length;
    //八个方向
    int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0},
            {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
    boolean[][] inQueue = new boolean[m][n];
    Queue<Point> queue = new ArrayDeque<>();
    inQueue[clickX][clickY] = true;
    queue.offer(new Point(clickX, clickY));
    while (!queue.isEmpty()) {
        Point point = queue.remove();
        int adjacentMines = 0;
        List<Point> readyInQueue = new ArrayList<>();
        for (int[] dir : dirs) {
            int x = point.x + dir[0];
            int y = point.y + dir[1];
            if (x < 0 || x > m - 1 || y < 0 || y > n - 1) {
                continue;
            }
            if (board[x][y] == 'M') {
                adjacentMines++;
            } else if (board[x][y] == 'E') {
                readyInQueue.add(new Point(x, y));
            }
        }
        //当前位置相邻没有地雷时，可以继续向周围搜索，将周围的点入队列；
        //当前位置相邻有地雷时，停止搜索
        if (adjacentMines == 0) {
            board[point.x][point.y] = 'B';
            for (Point newPoint : readyInQueue) {
                if (!inQueue[newPoint.x][newPoint.y]) {
                    inQueue[newPoint.x][newPoint.y] = true;
                    queue.offer(new Point(newPoint.x, newPoint.y));
                }
            }
        } else {
            board[point.x][point.y] = (char) ('0' + adjacentMines);
        }
    }
    return board;
}

class Point {
    int x;
    int y;

    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
```
