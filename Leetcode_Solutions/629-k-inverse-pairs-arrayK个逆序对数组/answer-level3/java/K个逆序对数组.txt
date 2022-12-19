#### 动态规划解法：

我们用 `f(i, j)` 表示数字 `[1 .. i]` 的排列中恰好包含 `j` 个逆序对的个数。在状态转移时，我们考虑数 `i` 放置的位置与逆序对个数的关系。我们在数字 `[1 .. i - 1]` 组成的排列中放入 `i` 时，有 `i` 种放置方法：如果将 `i` 放在最后，则逆序对数量不变；如果将 `i` 放在倒数第二个，则逆序对数量增加 `1`；如果将 `i` 放在第一个，则逆序对数量增加 `i - 1`。这是因为 `i` 是 `[1 .. i]` 中的最大值，因此将它放置在 `[1 .. i - 1]` 的排列中的任意一个位置，它都会与在它之后的那些数形成逆序对。如果它后面有 `k` 个数，则会形成 `k` 个逆序对。

因此我们可以写出状态转移方程：

```
f(i, j) = f(i - 1, j) + f(i - 1, j - 1) + ... + f(i - 1, j - i + 1)
```

边界条件为:
```
f(i, j0) = 0 if j0 < 0
f(0, 0) = 1
```

这个动态规划的时间复杂度为 $O(N^2*K)$，因此我们需要继续优化。可以发现，状态转移方程中的右侧是一段连续的和，我们将 `j` 变为 `j - 1`，有：

```
f(i, j - 1) = f(i - 1, j - 1) + f(i - 1, j - 2) + ... + f(i - 1, j - i)
```

将 `f(i, j)` 与 `f(i, j - 1)` 相比较，可以得到：

```
f(i, j) - f(i - 1, j) = f(i, j - 1) - f(i - 1, j - i)
==> f(i, j) = f(i, j - 1) + f(i - 1, j) - f(i - 1, j - i)
```

此时使用这个状态转移方程，动态规划的时间复杂度降低为 $O(N*K)$。

<![1000](https://pic.leetcode-cn.com/Figures/629/629_dp6Slide1.PNG),![1000](https://pic.leetcode-cn.com/Figures/629/629_dp6Slide2.PNG),![1000](https://pic.leetcode-cn.com/Figures/629/629_dp6Slide3.PNG),![1000](https://pic.leetcode-cn.com/Figures/629/629_dp6Slide4.PNG),![1000](https://pic.leetcode-cn.com/Figures/629/629_dp6Slide5.PNG),![1000](https://pic.leetcode-cn.com/Figures/629/629_dp6Slide6.PNG),![1000](https://pic.leetcode-cn.com/Figures/629/629_dp6Slide7.PNG),![1000](https://pic.leetcode-cn.com/Figures/629/629_dp6Slide8.PNG),![1000](https://pic.leetcode-cn.com/Figures/629/629_dp6Slide9.PNG),![1000](https://pic.leetcode-cn.com/Figures/629/629_dp6Slide10.PNG),![1000](https://pic.leetcode-cn.com/Figures/629/629_dp6Slide11.PNG),![1000](https://pic.leetcode-cn.com/Figures/629/629_dp6Slide12.PNG),![1000](https://pic.leetcode-cn.com/Figures/629/629_dp6Slide13.PNG),![1000](https://pic.leetcode-cn.com/Figures/629/629_dp6Slide14.PNG),![1000](https://pic.leetcode-cn.com/Figures/629/629_dp6Slide15.PNG),![1000](https://pic.leetcode-cn.com/Figures/629/629_dp6Slide16.PNG),![1000](https://pic.leetcode-cn.com/Figures/629/629_dp6Slide17.PNG),![1000](https://pic.leetcode-cn.com/Figures/629/629_dp6Slide18.PNG),![1000](https://pic.leetcode-cn.com/Figures/629/629_dp6Slide19.PNG),![1000](https://pic.leetcode-cn.com/Figures/629/629_dp6Slide20.PNG),![1000](https://pic.leetcode-cn.com/Figures/629/629_dp6Slide21.PNG)>


```Java [sol1]
public class Solution {
    public int kInversePairs(int n, int k) {
        int[][] dp = new int[n + 1][k + 1];
        int M = 1000000007;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k && j <= i * (i - 1) / 2; j++) {
                if (i == 1 && j == 0) {
                    dp[i][j] = 1;
                    break;
                } else if (j == 0)
                    dp[i][j] = 1;
                else {
                    int val = (dp[i - 1][j] + M - ((j - i) >= 0 ? dp[i - 1][j - i] : 0)) % M;
                    dp[i][j] = (dp[i][j - 1] + val) % M;
                }
            }
        }
        return dp[n][k];
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n*k)$。

* 空间复杂度：$O(n*k)$。