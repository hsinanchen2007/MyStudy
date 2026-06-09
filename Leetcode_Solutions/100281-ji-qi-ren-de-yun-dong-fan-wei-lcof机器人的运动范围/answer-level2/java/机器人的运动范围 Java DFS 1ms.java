### 解题思路
从$(0,0)$开始遍历，DFS和BFS都行，标记符合条件的点，最后可以遍历标记数组统计次数，也可以使用一个全局变量，在遍历的过程中统计，可以减少对数组的遍历，稍微快一点。

### 代码

```java
class Solution {
    private static int count = 0;

    public int movingCount(int m, int n, int k) {
        count = 0;
        boolean[][] vis = new boolean[m][n];
        dfs(vis, 0, 0, k);
        return count;
    }

    private static int dx[] = new int[] {-1, 0, 1, 0};
    private static int dy[] = new int[] {0, -1, 0, 1};

    public void dfs(boolean[][] vis, int i, int j, int limit) {
        if (vis[i][j]) return;
        vis[i][j] = true;
        ++count;
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < vis.length && y >= 0 && y < vis[0].length 
                && !vis[x][y] && countDigitValue(x) + countDigitValue(y) <= limit) {
                dfs(vis, x, y, limit);
            }
        }
    }

    public int countDigitValue(int x) {
        int res = 0;
        while (x > 0) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }
}
```