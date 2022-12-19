#### 方法一：动态规划


我们用 `f(start, n)` 表示骑士从数字 `start` 开始，跳了 `n - 1` 步得到不同的 `n` 位数字的个数。`f(start, n)` 可以从 `f(x, n - 1)` 转移而来，其中 `x` 是任意一个可以一步跳到 `start` 的数字。例如当 `start = 1`，时，`x` 可以为 `6` 或 `8`，因此有 `f(1, n) = f(6, n - 1) + f(8, n - 1)`。

最终的答案即为 `f(0, N) + f(1, N) + ... + f(9, N)`。我们可以使用滚动数组减少空间复杂度，这是因为 `f(start, n)` 只和 `f(x, n - 1)` 有关，因此在计算 `f(start, n)` 时，所有第二维小于 `n - 1` 的 `f` 值都不必存储。也就是说，我们只要实时存储当前正在计算的所有 `f` 值（`n` 位数字）以及上一个状态的 `f` 值（`n - 1` 位数字）即可。在 `Java` 代码中，我们使用 `dp[0][start]` 和 `dp[1][start]` 交替表示当前和上一个状态的 `f` 值。在 `Python` 代码中，我们使用 `dp2` 数组计算出当前的 `f` 值后，直接覆盖存储了上一个状态的 `f` 值的 `dp` 数组。

```Java [sol1]
class Solution {
    public int knightDialer(int N) {
        int MOD = 1_000_000_007;
        int[][] moves = new int[][]{
            {4,6},{6,8},{7,9},{4,8},{3,9,0},
            {},{1,7,0},{2,6},{1,3},{2,4}};

        int[][] dp = new int[2][10];
        Arrays.fill(dp[0], 1);
        for (int hops = 0; hops < N-1; ++hops) {
            Arrays.fill(dp[~hops & 1], 0);
            for (int node = 0; node < 10; ++node)
                for (int nei: moves[node]) {
                    dp[~hops & 1][nei] += dp[hops & 1][node];
                    dp[~hops & 1][nei] %= MOD;
                }
        }

        long ans = 0;
        for (int x: dp[~N & 1])
            ans += x;
        return (int) (ans % MOD);
    }
}
```

```Python [sol1]
class Solution(object):
    def knightDialer(self, N):
        MOD = 10**9 + 7
        moves = [[4,6],[6,8],[7,9],[4,8],[3,9,0],[],
                     [1,7,0],[2,6],[1,3],[2,4]]

        dp = [1] * 10
        for hops in xrange(N-1):
            dp2 = [0] * 10
            for node, count in enumerate(dp):
                for nei in moves[node]:
                    dp2[nei] += count
                    dp2[nei] %= MOD
            dp = dp2
        return sum(dp) % MOD
```

**复杂度分析**

* 时间复杂度：$O(N)$。

* 空间复杂度：如果使用滚动数组，则空间复杂度为 $O(1)$，也可以看成 $O(10)$。否则空间复杂度为 $O(N)$。