使用visited数组记录访问过的位置
```Java
    public int movingCount(int m, int n, int k) {
        boolean[][] visited = new boolean[m][n];
        return dfs(k, m, n, 0, 0, visited);
    }

    private int dfs(int threshold, int rows, int cols, int i, int j, boolean[][] visited) {
        if (i < 0 || j < 0 || i >= rows || j >= cols || visited[i][j]) return 0;
        visited[i][j] = true;
        if (digitSum(i) + digitSum(j) > threshold) return 0;
        int count = 1;
        count += dfs(threshold, rows, cols, i-1, j, visited);
        count += dfs(threshold, rows, cols, i+1, j, visited);
        count += dfs(threshold, rows, cols, i, j-1, visited);
        count += dfs(threshold, rows, cols, i, j+1, visited);
        return count;
    }
    private int digitSum(int num) {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num = num / 10;
        }
        return sum;
    }
```
这是我的[LeetCode分类题解](https://github.com/caipengbo/LeetCode)（每日更新, issue内有总结），和我一起每日刷题吧！