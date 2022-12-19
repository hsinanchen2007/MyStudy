#### 方法 1：动态规划

**想法和算法**

这是一个复杂的问题，很难抽象出解题思路。

首先，找出需要保留的列数，而不是需要删除的列数。最后，可以相减得到答案。

假设我们一定保存第一列 `C`，那么保存的下一列 `D` 就必须保证每行都是字典有序的，也就是 `C[i] <= D[i]`。那么我们就可以删除 `C` 和 `D` 之间的所有列。

我们可以用动态规划来解决这个问题，让 `dp[k]` 表示在输入为 `[row[k:] for row in A]` 时保存的列数，那么 `dp[k]` 的递推式显而易见。

```Java []
class Solution {
    public int minDeletionSize(String[] A) {
        int W = A[0].length();
        int[] dp = new int[W];
        Arrays.fill(dp, 1);
        for (int i = W-2; i >= 0; --i)
            search: for (int j = i+1; j < W; ++j) {
                for (String row: A)
                    if (row.charAt(i) > row.charAt(j))
                        continue search;

                dp[i] = Math.max(dp[i], 1 + dp[j]);
            }

        int kept = 0;
        for (int x: dp)
            kept = Math.max(kept, x);
        return W - kept;
    }
}
```

```Python []
class Solution(object):
    def minDeletionSize(self, A):
        W = len(A[0])
        dp = [1] * W
        for i in xrange(W-2, -1, -1):
            for j in xrange(i+1, W):
                if all(row[i] <= row[j] for row in A):
                    dp[i] = max(dp[i], 1 + dp[j])

        return W - max(dp)
```

**复杂度分析**

* 时间复杂度：$O(N * W^2)$，其中 $N$ 是 `A` 的长度，$W$ 是 `A` 中每个单词的长度。
* 空间复杂度：$O(W)$。