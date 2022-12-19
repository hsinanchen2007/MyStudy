#### 方法 1：线性扫描

**想法**

如  **最小差值 I** 问题的解决方法，较小的 `A[i]` 将增加，较大的 `A[i]` 将变小。

**算法**

我们可以对上述想法形式化表述：如果 `A[i] < A[j]`，我们不必考虑当 `A[i]` 增大时 `A[j]` 会减小。这是因为区间 `(A[i] + K, A[j] - K)` 是 `(A[i] - K, A[j] + K)` 的子集（这里，当 `a > b` 时 `(a, b)` 表示 `(b, a)` ）。

这意味着对于 `(up, down)` 的选择一定不会差于 `(down, up)`。我们可以证明其中一个区间是另一个的子集，通过证明 `A[i] + K` 和 `A[j] - K` 是在 `A[i] - K` 和 `A[j] + K` 之间。

对于有序的 `A`，设 `A[i]` 是最大的需要增长的 `i`，那么 `A[0] + K, A[i] + K, A[i+1] - K, A[A.length - 1] - K` 就是计算结果的唯一值。


```Java []
class Solution {
    public int smallestRangeII(int[] A, int K) {
        int N = A.length;
        Arrays.sort(A);
        int ans = A[N-1] - A[0];

        for (int i = 0; i < A.length - 1; ++i) {
            int a = A[i], b = A[i+1];
            int high = Math.max(A[N-1] - K, a + K);
            int low = Math.min(A[0] + K, b - K);
            ans = Math.min(ans, high - low);
        }
        return ans;
    }
}
```

```Python []
class Solution(object):
    def smallestRangeII(self, A, K):
        A.sort()
        mi, ma = A[0], A[-1]
        ans = ma - mi
        for i in xrange(len(A) - 1):
            a, b = A[i], A[i+1]
            ans = min(ans, max(ma-K, a+K) - min(mi+K, b-K))
        return ans
```

**复杂度分析**

* 时间复杂度：$O(N \log N)$，其中 $N$ 是 `A` 的长度。
* 空间复杂度：$O(1)$，额外空间就是自带排序算法的空间。