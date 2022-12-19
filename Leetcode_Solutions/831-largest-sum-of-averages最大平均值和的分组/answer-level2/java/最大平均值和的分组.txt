#### 动态规划：

我们可以使用动态规划来解决这个问题。设 `dp(i, k)` 表示将数组 `A` 中的前 `i` 个元素 `A[:i]` 分成 `k` 个相邻的非空子数组，可以得到的最大分数。`dp(i, k)` 的值可以通过 `dp(j, k - 1)` 转移而来，其中 `j < i`，状态转移方程为：

```
dp(i, k) = max(dp(j, k - 1) + average(j + 1, i))
dp(i, 0) = average(0, i)
```

其中 `average(j + 1, i)` 表示 `A[j + 1]` 到 `A[i]` 的平均值 `(A[j + 1] + A[j + 2] + ... + A[i]) / (i - j)`。我们可以通过预处理出前缀和 `P[x + 1] = A[0] + A[1] + ... + A[x]`，从而用 `average(j + 1, i) = (P[i + 1] - P[j + 1]) / (i - j)` 在常数时间内得到平均值。

我们可以继续优化动态规划的空间复杂度。可以发现，如果设 `dp(i, k)` 为第 `k` 层的结果，那么第 `k` 层的结果实际上只和第 `k - 1` 层有关，因此我们可以使用滚动数组优化空间，即只使用两个一维数组。进一步而言。如果我们从后往前进行动态规划，即设 `dp(i, k)` 表示数组 `A` 中从第 `i` 个元素到结尾 `A[i:]` 分成 `k` 个相邻的非空子数组，可以得到的最大分数，那么状态转移方程将变为：

```
dp(i, k) = max(dp(j, k - 1) + average(i, j - 1))
dp(i, 0) = average(i, n - 1)
```

其中 `j > i`，那么我们在计算第 `k` 层的结果，并且 `i` 是依次递增的时候，第 `k` 层的结果并不会覆盖掉第 `k - 1` 层的结果，因为当 `dp(i, k)` 被计算出并且覆盖了 `dp(i, k - 1)` 时，接下来的所有 `dp(i0, k), i0 > i` 都不会从 `dp(i, k - 1)` 转移而来。因此我们最终只需要用一个一维数组，就能完成动态规划。

```Java [sol1]
class Solution {
    public double largestSumOfAverages(int[] A, int K) {
        int N = A.length;
        double[] P = new double[N+1];
        for (int i = 0; i < N; ++i)
            P[i+1] = P[i] + A[i];

        double[] dp = new double[N];
        for (int i = 0; i < N; ++i)
            dp[i] = (P[N] - P[i]) / (N - i);

        for (int k = 0; k < K-1; ++k)
            for (int i = 0; i < N; ++i)
                for (int j = i+1; j < N; ++j)
                    dp[i] = Math.max(dp[i], (P[j]-P[i]) / (j-i) + dp[j]);

        return dp[0];
    }
}
```

```Python [sol1]
class Solution(object):
    def largestSumOfAverages(self, A, K):
        P = [0]
        for x in A: P.append(P[-1] + x)
        def average(i, j):
            return (P[j] - P[i]) / float(j - i)

        N = len(A)
        dp = [average(i, N) for i in xrange(N)]
        for k in xrange(K-1):
            for i in xrange(N):
                for j in xrange(i+1, N):
                    dp[i] = max(dp[i], average(i, j) + dp[j])

        return dp[0]
```

**复杂度分析**

* 时间复杂度：$O(K * N^2)$，其中 $N$ 是数组 `A` 的长度。

* 空间复杂度：$O(N)$。