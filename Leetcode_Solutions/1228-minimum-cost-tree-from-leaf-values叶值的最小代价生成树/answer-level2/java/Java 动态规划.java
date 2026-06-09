```java
/**
 * 比较基础的动态规划问题
 * 定义状态: f[i][j] 表示 arr 的 [i, j] 构造二叉树的最小和
 * 状态转移: f[i][j] = min{ f[i][k] + f[k+1][j] + Max(i,k) * Max(k+1,j) }
 */
class Solution {
    private int[][] max, f;
    public int mctFromLeafValues(int[] arr) {
        int n = arr.length;
        max = new int[n][n];    // 可以用 ST 表优化到 o(nlogn) 预处理 + o(1) 查询
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                max[i][j] = i == j ? arr[j] : Math.max(max[i][j - 1], arr[j]);
            }
        }
        f = new int[n][n];
        return dp(0, n - 1);
    }

    int dp(int i, int j) {
        if (f[i][j] > 0 || i == j) {
            return f[i][j];  // 初值 f[i][i] 为 0
        }
        f[i][j] = Integer.MAX_VALUE;
        for (int k = i; k < j; k++) {
            f[i][j] = Math.min(f[i][j], dp(i, k) + dp(k + 1, j) + max[i][k] * max[k + 1][j]);
        }
        return f[i][j];
    }
}
```