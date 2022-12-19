#### 方法一：动态规划

虽然解决这题的代码很短，但它的算法并不是很容易设计。我们会用动态规划先求出包括空序列的所有子序列，再返回答案之前再减去空序列。

我们用 `dp[k]` 表示 `S[0 .. k]` 可以组成的不同子序列的数目。如果 `S` 中的所有字符都不相同，例如 `S = "abcx"`，那么状态转移方程就是简单的 `dp[k] = dp[k-1] * 2`，例如 `dp[2] = 8`，它包括 `("", "a", "b", "c", "ab", "ac", "bc", "abc")` 这 `8` 个不同的子序列，而 `dp[3]` 在这些子序列的末尾增加 `x`，就可以得到额外的 `8` 个不同的子序列，即 `("x", "ax", "bx", "cx", "abx", "acx", "bcx", "abcx")`，因此 `dp[3] = 8 * 2 = 16`。

但当 `S` 中有相同字母的时候，就要考虑重复计数的问题了，例如当 `S = "abab"` 时，我们有：

* `dp[0] = 2`，它包括 `("", "a")`；

* `dp[1] = 4`，它包括 `("", "a", "b", "ab")`；

* `dp[2] = 7`，它包括 `("", "a", "b", "aa", "ab", "ba", "aba")`；

* `dp[3] = 12`，它包括 `("", "a", "b", "aa", "ab", "ba", "bb", "aab", "aba", "abb", "bab", "abab")`。

当从 `dp[2]` 转移到 `dp[3]` 时，我们只会在 `dp[2]` 中的 `("b", "aa", "ab", "ba", "aba")` 的末尾增加 `b`，而忽略掉 `("", "a")`，因为它们会得到重复的子序列。我们可以发现，这里的 `("", "a")` 刚好就是 `dp[0]`，也就是上一次增加 `b` 之前的子序列集合。因此我们就得到了如下的状态转移方程：

`dp[k] = 2 * dp[k - 1] - dp[last[S[k]] - 1]`

即在计算 `dp[k]` 时，首先会将 `dp[k - 1]` 对应的子序列的末尾添加 `S[k]` 得到额外的 `dp[k - 1]` 个子序列，并减去重复出现的子序列数目，这个数目即为上一次添加 `S[k]` 之前的子序列数目 `dp[last[S[k]] - 1]`。

```Java [sol1]
class Solution {
    public int distinctSubseqII(String S) {
        int MOD = 1_000_000_007;
        int N = S.length();
        int[] dp = new int[N+1];
        dp[0] = 1;

        int[] last = new int[26];
        Arrays.fill(last, -1);

        for (int i = 0; i < N; ++i) {
            int x = S.charAt(i) - 'a';
            dp[i+1] = dp[i] * 2 % MOD;
            if (last[x] >= 0)
                dp[i+1] -= dp[last[x]];
            dp[i+1] %= MOD;
            last[x] = i;
        }

        dp[N]--;
        if (dp[N] < 0) dp[N] += MOD;
        return dp[N];
    }
}
```

```Python [sol1]
class Solution(object):
    def distinctSubseqII(self, S):
        dp = [1]
        last = {}
        for i, x in enumerate(S):
            dp.append(dp[-1] * 2)
            if x in last:
                dp[-1] -= dp[last[x]]
            last[x] = i

        return (dp[-1] - 1) % (10**9 + 7)
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中, where $N$ 是字符串 `S` 的长度。

* 空间复杂度：$O(N)$，也可以将空间复杂度优化到 $O(1)$。