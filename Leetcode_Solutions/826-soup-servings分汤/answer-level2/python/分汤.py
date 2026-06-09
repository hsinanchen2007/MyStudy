#### 动态规划：

首先，由于四种分配操作都是 `25` 的倍数，因此我们可以将 `N` 除以 `25`（如果有余数，则补 `1`），并将分配操作变为 `(4, 0)`，`(3, 1)`，`(2, 2)` 和 `(1, 3)`。

当 `N` 较小时，我们可以用动态规划来解决这个问题。设 `dp(i, j)` 表示汤 `A` 和汤 `B` 分别剩下 `i` 和 `j` 份时，所求的概率值。状态转移方程为：

```
dp(i, j) = 1/4 * (dp(i - 4, y) + dp(i - 3, y - 1) + dp(i - 2, y - 2) + dp(i - 1, y - 3))
```

边界条件为：

```
dp(i, j) = 0.5   if i <= 0 and j <= 0
dp(i, j) = 1.0   if i <= 0 and j > 0
dp(i, j) = 0.0   if i > 0 and j <= 0
```

即如果同时分配完（边界条件中的第一行），概率值为 `1.0` 的一半即为 `0.5`；如果汤 `A` 先分配完，概率值为 `1.0`；如果汤 `B` 先分配完，概率值为 `0.0`。

这个动态规划的时间复杂度是 $O(N^2)$，即使将 `N` 除以 `25` 之后，仍然没法在短时间内得到答案，因此我们需要尝试一些别的思路。可以发现，分配操作有 `(4, 0)`，`(3, 1)`，`(2, 2)` 和 `(1, 3)` 四种，那么在一次分配中，汤 `A` 平均会少 `(4 + 3 + 2 + 1) / 4 = 2.5` 份，汤 `B` 平均会少 `(0 + 1 + 2 + 3) / 4 = 1.5` 份。因此在 `N` 非常大的时候，`A` 会有很大的概率比 `B` 先分配完，所有概率应该非常接近 `1`。事实上，当 `N >= 500 * 25` 时，所求概率已经大于 `0.999999` 了（可以通过上面的动态规划方法求出），它和 `1` 的误差（无论是绝对误差还是相对误差）都小于 `10^-6`。因此在 `N >= 500 * 25` 时，我们只需要输出 `1` 作为答案即可。在其它的情况下，我们使用动态规划计算出答案。

```Java [sol1]
class Solution {
    public double soupServings(int N) {
        N = N/25 + (N%25 > 0 ? 1 : 0);
        if (N >= 500) return 1.0;

        double[][] memo = new double[N+1][N+1];
        for (int s = 0; s <= 2*N; ++s) {
            for (int i = 0; i <= N; ++i) {
                int j = s-i;
                if (j < 0 || j > N) continue;
                double ans = 0.0;
                if (i == 0) ans = 1.0;
                if (i == 0 && j == 0) ans = 0.5;
                if (i > 0 && j > 0) {
                    ans = 0.25 * (memo[M(i-4)][j] + memo[M(i-3)][M(j-1)] +
                                  memo[M(i-2)][M(j-2)] + memo[M(i-1)][M(j-3)]);
                }
                memo[i][j] = ans;

            }
        }
        return memo[N][N];
    }

    public int M(int x) { return Math.max(0, x); }
}
```

```Python [sol1]
class Solution(object):
    def soupServings(self, N):
        Q, R = divmod(N, 25)
        N = Q + (R > 0)
        if N >= 500: return 1

        memo = {}
        def dp(x, y):
            if (x, y) not in memo:
                if x <= 0 or y <= 0:
                    ans = 0.5 if x<=0 and y<=0 else 1.0 if x<=0 else 0.0
                else:
                    ans = 0.25 * (dp(x-4,y)+dp(x-3,y-1)+dp(x-2,y-2)+dp(x-1,y-3))
                memo[x, y] = ans
            return memo[x, y]

        return dp(N, N)
```

**复杂度分析**

* 时间复杂度：$O(1)$，因为存在常数 $C$，使得当 $N > C$ 时，所求的概率和 `1` 的误差在 `10^-6` 以内。

* 空间复杂度：$O(1)$，原因同上。