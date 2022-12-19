```
  /**
     * DFS 
     *
     * @param m
     * @param n
     * @param k
     * @return
     */
    int ans = 0;

    public int movingCount(int m, int n, int k) {
        dfs(new int[m][n], 0, 0, k);
        return ans;
    }

    /**
     * 深度搜索
     * @param area 记忆走过的路径
     * @param x  x坐标
     * @param y  y坐标
     * @param k
     */
    public void dfs(int[][] area, int x, int y, int k) {
        if (x >= 0 && y >= 0 && x < area[0].length && y < area.length) {
            // 当前位置没有超出格子
            if (area[y][x] == 0 && sum(x) + sum(y) <= k) {
                // 没有被访问过且位数之和不大于k
                ans++;
                // 标记为已访问
                area[y][x] = 1;
                // 沿着上下左右四个方向遍历
                dfs(area, x + 1, y, k);
                dfs(area, x - 1, y, k);
                dfs(area, x, y + 1, k);
                dfs(area, x, y - 1, k);
            }
        }
    }

    /**
     * 计算位数之和
     * @param x
     * @return
     */
    private int sum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x = x / 10;
        }
        return sum;
    }

```
