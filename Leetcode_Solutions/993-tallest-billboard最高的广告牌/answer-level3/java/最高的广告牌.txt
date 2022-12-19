#### 方法 1：动态规划

**想法**

对于每一根钢筋 `x`，我们会写下 `+x`，`-x` 或者 `0`。我们的目标是最终得到结果 `0` 并让正数之和最大。我们记所有写下的正数之和为 *score*。例如，`+1 +2 +3 -6` 的 score 为 `6`。

因为 `sum(rods)` 的大小限制，就说明可以利用这个性质。事实上，如果之前已经写下了一些数字，那么就不需要考虑这些数字是如何得到的。例如，`rods = [1, 2, 2, 3]`，我们可以用 3 种方法得到和为 `3`，但只考虑最终的 score 为 `3`。数字之和的上界是 `10001`，因为只有 `[-5000, 5000]` 区间内的整数是可能的值。

**算法**

`dp[i][s]` 表示当我们可以使用 `rods[j]` `(j >= i)` 时能得到的最大 `score`，由于之前写下的数字和为 `s`（不统计在 score 内）。例如，`rods = [1, 2, 3, 6]`，可以有 `dp[1][1] = 5`，在写下 `1` 之后，可以写下 `+2 +3 -6` 使得剩下的 `rods[i:]` 获得 score 为 `5`。

边界情况：`dp[rods.length][s]` 是 `0` 当 `s == 0`，剩余情况为 `-infinity` 。递推式为 `dp[i][s] = max(dp[i+1][s], dp[i+1][s-rods[i]], rods[i] + dp[i+1][s+rods[i]])`。

```Java []
class Solution {
    int NINF = Integer.MIN_VALUE / 3;
    Integer[][] memo;
    public int tallestBillboard(int[] rods) {
        int N = rods.length;
        // "memo[n][x]" will be stored at memo[n][5000+x]
        // Using Integer for default value null
        memo = new Integer[N][10001];
        return (int) dp(rods, 0, 5000);
    }

    public int dp(int[] rods, int i, int s) {
        if (i == rods.length) {
            return s == 5000 ? 0 : NINF;
        } else if (memo[i][s] != null) {
            return memo[i][s];
        } else {
            int ans = dp(rods, i+1, s);
            ans = Math.max(ans, dp(rods, i+1, s-rods[i]));
            ans = Math.max(ans, rods[i] + dp(rods, i+1, s+rods[i]));
            memo[i][s] = ans;
            return ans;
        }
    }
}
```

```Python []
from functools import lru_cache
class Solution:
    def tallestBillboard(self, rods):
        @lru_cache(None)
        def dp(i, s):
            if i == len(rods):
                return 0 if s == 0 else float('-inf')
            return max(dp(i + 1, s),
                       dp(i + 1, s - rods[i]),
                       dp(i + 1, s + rods[i]) + rods[i])

        return dp(0, 0)
```

**复杂度分析**

* 时间复杂度：$O(NS)$，其中 $N$ 是 `rods` 的长度，$S$ 是 $\sum \text{rods}[i]$。
* 空间复杂度：$O(NS)$。

#### 方法 2：折半搜索

**想法**

暴力搜索的复杂度可以用“折半搜索”优化。在这个问题中，我们有 $3^N$ 种可行方案，对于每个钢筋 `x` 可以考虑 `+x`，`-x`，或者 `0` ，我们要让暴力的速度更快。

我们可以让前 $3^{N/2}$ 和后一半分开来考虑，然后再合并他们。例如，如果有钢筋 `[1, 3, 5, 7]`，那么前两根钢筋可以构成九种状态：`[0+0, 0+3, 0-3, 1+0, 1+3, 1-3, -1+0, -1+3, -1-3]`，后两根钢筋也可以构成九种状态。

我们对每个状态记录正数之和，以及负数绝对值之和。例如，`+1 +2 -3 -4` 记为 `(3, 7)`。同时记状态的 *delta* 为两者之差 `3-7`，所以这个状态的 `delta` 为 `-4`。

我们的目标是将两个状态合并，使得 `delta` 之和为 `0`。`score` 是所有正数之和，我们希望获得最高的 `score`。对于每个 `delta` 我们只会记录具有最高 `score` 的状态。

**算法**

将钢筋分成左右两半：左侧和右侧。

对于每一半，暴力计算可达的所有状态，如上定义。然后针对所有状态，记录下 `delta` 和最大的 `score`。

然后我们有左右两半的 `[(delta, score)]` 信息。我们找到 `delta` 为 `0` 时最大的 `score` 和。

```Java []
import java.awt.Point;

class Solution {
    public int tallestBillboard(int[] rods) {
        int N = rods.length;
        Map<Integer, Integer> Ldelta = make(Arrays.copyOfRange(rods, 0, N/2));
        Map<Integer, Integer> Rdelta = make(Arrays.copyOfRange(rods, N/2, N));

        int ans = 0;
        for (int d: Ldelta.keySet())
            if (Rdelta.containsKey(-d))
                ans = Math.max(ans, Ldelta.get(d) + Rdelta.get(-d));

        return ans;
    }

    public Map<Integer, Integer> make(int[] A) {
        Point[] dp = new Point[60000];
        int t = 0;
        dp[t++] = new Point(0, 0);
        for (int v: A) {
            int stop = t;
            for (int i = 0; i < stop; ++i) {
                Point p = dp[i];
                dp[t++] = new Point(p.x + v, p.y);
                dp[t++] = new Point(p.x, p.y + v);
            }
        }

        Map<Integer, Integer> ans = new HashMap();
        for (int i = 0; i < t; ++i) {
            int a = dp[i].x;
            int b = dp[i].y;
            ans.put(a-b, Math.max(ans.getOrDefault(a-b, 0), a));
        }

        return ans;
    }
}
```

```Python []
class Solution(object):
    def tallestBillboard(self, rods):
        def make(A):
            states = {(0, 0)}
            for x in A:
                states |= ({(a+x, b) for a, b in states} |
                           {(a, b+x) for a, b in states})

            delta = {}
            for a, b in states:
                delta[a-b] = max(delta.get(a-b, 0), a)
            return delta

        N = len(rods)
        Ldelta = make(rods[:N/2])
        Rdelta = make(rods[N/2:])

        ans = 0
        for d in Ldelta:
            if -d in Rdelta:
                ans = max(ans, Ldelta[d] + Rdelta[-d])
        return ans
```

**复杂度分析**

* 时间复杂度：$O(3^{N/2})$，其中 $N$ 是 `rods` 的长度。
* 空间复杂度：$O(3^{N/2})$。
