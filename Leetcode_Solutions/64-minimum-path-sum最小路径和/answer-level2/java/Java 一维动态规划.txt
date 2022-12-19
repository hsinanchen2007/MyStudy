使用一维动态规划，设置一个数组`dp[n]`，表示数组遍历到现在这个节点时，`grid[0][0]`到这一列的路径最小值。

为什么可以只用一维数组呢？我们可以考虑一下，对于不在左边界或上边界上的值，从原点到这个节点的路径最小值就是 *原点到该节点左节点的路径最小值* 和 *原点到该节点上边的路径最小值* 中的较小值，加上该节点的值。而*原点到该节点左节点的路径最小值* 实际上就是 `dp[j-1]`, *原点到该节点上边的路径最小值* 就是还没更新的`dp[j]`。

所以上面这个关系可以表示为：`dp[j] = Math.min(dp[j - 1], dp[j])

```java
public int minPathSum (int[][] grid) {
    if (grid.length == 0 || grid[0].length == 0) {
        return 0;
    }
    int m = grid.length, n = grid[0].length;
    int[] dp = new int[n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                dp[j] = dp[j];
            } else if (i == 0) {
                dp[j] = dp[j - 1];
            } else {
                dp[j] = Math.min(dp[j], dp[j - 1]);
            }
            dp[j] += grid[i][j];
        }
    }
    return dp[n - 1];
}
```