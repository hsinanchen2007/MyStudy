#### 方法 1：动态规划

**想法**

最大值 `v` 一定会被用在树的根节点上，设 `dp(v)` 是以 `v` 为根节点的树种类数。

如果树根节点有孩子 `x` 和 `y` 满足 `x * y == v`，那么就有 `dp(x) * dp(y)` 种方法构造这棵树。

总共会有 $\sum_{x * y = v} \text{dp}(x) * \text{dp}(y)$ 种方法构造以 `v` 为根的树。

**算法**

实际上，令 `dp[i]` 表示已 `A[i]` 为树根的树的种类数。

在上面的例子中我们知道 `x < v` 和 `y < v`，我们可以用动态规划的方法按照升序值计算 `dp[i]` 的值。

对于树根值 `A[i]`，需要找到所有可能的孩子节点取值 `A[j]` 和 `A[i] / A[j]`（显然要有 `A[j] * (A[i] / A[j]) = A[i]`）。为了快速的计算，我们使用 `index` 数组快速查找：如果 `A[k] = A[i] / A[j]`，那么 `index[A[i] / A[j]] = k`。

之后，我们将所有可能的值 `dp[j] * dp[k]`（其中 `j < i, k < i`）加入结果 `dp[i]` 中。在 Java 实现中，我们谨慎的使用了 `long` 类型避免溢出错误。

```Java []
class Solution {
    public int numFactoredBinaryTrees(int[] A) {
        int MOD = 1_000_000_007;
        int N = A.length;
        Arrays.sort(A);
        long[] dp = new long[N];
        Arrays.fill(dp, 1);

        Map<Integer, Integer> index = new HashMap();
        for (int i = 0; i < N; ++i)
            index.put(A[i], i);

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < i; ++j) {
                if (A[i] % A[j] == 0) { // A[j] is left child
                    int right = A[i] / A[j];
                    if (index.containsKey(right)) {
                        dp[i] = (dp[i] + dp[j] * dp[index.get(right)]) % MOD;
                    }
                }
            }

        long ans = 0;
        for (long x: dp) ans += x;
        return (int) (ans % MOD);
    }
}
```

```Python []
class Solution(object):
    def numFactoredBinaryTrees(self, A):
        MOD = 10 ** 9 + 7
        N = len(A)
        A.sort()
        dp = [1] * N
        index = {x: i for i, x in enumerate(A)}
        for i, x in enumerate(A):
            for j in xrange(i):
                if x % A[j] == 0: #A[j] will be left child
                    right = x / A[j]
                    if right in index:
                        dp[i] += dp[j] * dp[index[right]]
                        dp[i] %= MOD

        return sum(dp) % MOD
```


**复杂度分析**

* 时间复杂度：$O(N^2)$，其中 $N$ 是 `A` 的长度。这是由于两层循环 `i` 和 `j`。
* 空间复杂度：$O(N)$，`dp` 和 `index` 使用的空间。