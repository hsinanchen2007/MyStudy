```
class Solution {
    public int numberOfPatterns(int m, int n) {
        boolean[][] visit = new boolean[3][3];
        return 4 * (dfs(visit, m, n, 0, 0, 0) + dfs(visit, m, n, 0, 0, 1)) + dfs(visit, m, n, 0, 1, 1);
    }

    private int dfs(boolean[][] visit, int m, int n, int count, int x, int y) {
        int res = 0;
        ++count;
        if (count >= m) {
            ++res;
        }
        if (count == n) {
            return res;
        }
        visit[x][y] = true;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (canVisit(visit, x, y, i, j)) {
                    res += dfs(visit, m, n, count, i, j);
                }
            }
        }
        visit[x][y] = false;
        return res;
    }

    private boolean canVisit(boolean[][] visit, int x1, int y1, int x2, int y2) {
        if (visit[x2][y2]) {
            return false;
        }
        if (Math.abs(x1 - x2) <= 1 && Math.abs(y1 - y2) <= 1) {
            return true;
        }
        if (Math.abs(x1 - x2) != 1 && Math.abs(y1 - y2) != 1) {
            return visit[(x1 + x2) / 2][(y1 + y2) / 2];
        }
        return true;
    }
}
```
