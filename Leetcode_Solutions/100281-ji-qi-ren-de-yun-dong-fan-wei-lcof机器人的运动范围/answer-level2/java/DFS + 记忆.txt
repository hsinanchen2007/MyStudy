# 代码
```java
class Solution {
    private int res = 0, global_m, global_n, global_k;
    private boolean[][] selected;
    private int[] memo;

    public int movingCount(int m, int n, int k) {
        global_m = m;
        global_n = n;
        global_k = k;
        int bound = Math.max(m, n);
        memo = new int[bound];
        selected = new boolean[m][n];
        for (int i = 0; i < bound; ++i)
            memo[i] = computeSum(i);
        dfs(0, 0);
        return res;
    }

    private int computeSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    private void dfs(int row, int col) {
        ++res;
        selected[row][col] = true;
        if (row + 1 < global_m && !selected[row + 1][col] && memo[row + 1] + memo[col] <= global_k)
            dfs(row + 1, col);
        if (col + 1 < global_n && !selected[row][col + 1] && memo[row] + memo[col + 1] <= global_k)
            dfs(row, col + 1);
        if (row > 0 && !selected[row - 1][col] && memo[row - 1] + memo[col] <= global_k)
            dfs(row - 1, col);
        if (col > 0 && !selected[row][col - 1] && memo[row] + memo[col - 1] <= global_k)
            dfs(row, col - 1);
    }
}
```
