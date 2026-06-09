# 直接遍历

- 发现腐烂的橘子后，直接丢弃 `grid[i][j] = 0;` 减少下次遍历重复访问
- 通过 `dx` , `dy` 作四连通
- 隔壁要腐烂时，先预处理 `grid[x][y] = -1;` 腐烂中，以免同一层遍历时受影响
- 易错点
    - 发现将要腐烂的橘子时，直接 `= 2`，导致一次性全都腐烂掉了
    - 别忘了查看是否还有好的橘子，返回 `-1`
```java
public int orangesRotting(int[][] grid) {
    int[] dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1}; // 四连通
    boolean rotting = false; // 是否发生腐烂
    int rows = grid.length, cols = grid[0].length;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 0) continue;
            if (grid[i][j] == 2) {
                grid[i][j] = 0; // 烂过可以丢了: flood-fill
                for (int di = 0; di < 4; di++) {
                    int x = i + dx[di], y = j + dy[di];
                    if (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1) {
                        grid[x][y] = -1; // rotting... 腐烂中
                        rotting = true;
                    }
                }
            }
        }
    }

    if (!rotting) { // 无腐烂现象
        // 是否还有好的
        for (int[] row : grid) {
            for (int o : row) {
                if (o == 1) return -1;
            }
        }

        // 没有好的了
        return 0;
    }

    // 腐烂
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == -1) grid[i][j] = 2;
        }
    }

    // 递归
    int seconds = orangesRotting(grid);

    return seconds == -1 ? -1 : seconds + 1;
}
```

# 广度优先模板 Queue

```java
private int[] dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1}; // 四连通
int rows, cols;

public int orangesRotting(int[][] grid) {
    Queue<Orange> queue = new LinkedList<>();
    rows = grid.length;
    cols = grid[0].length;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) queue.add(new Orange(i, j));
        }
    }

    int res = rotting(-1, grid, queue);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) return -1;
        }
    }
    return res == -1 ? 0 : res;
}

private int rotting(int second, int[][] grid, Queue<Orange> queue) {
    if (queue.isEmpty()) return second;

    Queue<Orange> next = new LinkedList<>();
    while (!queue.isEmpty()) {
        Orange orange = queue.remove();
        for (int di = 0; di < 4; di++) {
            grid[orange.x][orange.y] = 0;
            int x = orange.x + dx[di], y = orange.y + dy[di];
            if (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1) {
                grid[x][y] = 2; // visited
                next.add(new Orange(x, y));
            }
        }
    }

    return rotting(second + 1, grid, next);
}

class Orange {
    int x, y;

    public Orange(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
```
