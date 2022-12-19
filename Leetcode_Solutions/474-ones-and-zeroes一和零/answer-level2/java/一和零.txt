#### 方法一：动态规划

这道题和经典的背包问题很类似，不同的是在背包问题中，我们只有一种容量，而在这道题中，我们有 `0` 和 `1` 两种容量。每个物品（字符串）需要分别占用 `0` 和 `1` 的若干容量，并且所有物品的价值均为 `1`。因此我们可以使用二维的动态规划。

我们用 `dp(i, j)` 表示使用 `i` 个 `0` 和 `j` 个 `1`，最多能拼出的字符串数目，那么状态转移方程为：

```
dp(i, j) = max(1 + dp(i - cost_zero[k], j - cost_one[k]))
    if i >= cost_zero[k] and j >= cost_one[k]
```

其中 `k` 表示第 `k` 个字符串，`cost_zero[k]` 和 `cost_one[k]` 表示该字符串中 `0` 和 `1` 的个数。我们依次枚举这些字符串，并根据状态转移方程更新所有的 `dp(i, j)`。注意由于每个字符串只能使用一次（即有限背包），因此在更新 `dp(i, j)` 时，`i` 和 `j` 都需要从大到小进行枚举。

最终的答案即为所有 `dp(i, j)` 中的最大值。

<![1300](https://pic.leetcode-cn.com/Figures/474_Ones_ZeroesSlide1.PNG),![1300](https://pic.leetcode-cn.com/Figures/474_Ones_ZeroesSlide2.PNG),![1300](https://pic.leetcode-cn.com/Figures/474_Ones_ZeroesSlide3.PNG),![1300](https://pic.leetcode-cn.com/Figures/474_Ones_ZeroesSlide4.PNG),![1300](https://pic.leetcode-cn.com/Figures/474_Ones_ZeroesSlide5.PNG),![1300](https://pic.leetcode-cn.com/Figures/474_Ones_ZeroesSlide6.PNG),![1300](https://pic.leetcode-cn.com/Figures/474_Ones_ZeroesSlide7.PNG),![1300](https://pic.leetcode-cn.com/Figures/474_Ones_ZeroesSlide8.PNG),![1300](https://pic.leetcode-cn.com/Figures/474_Ones_ZeroesSlide9.PNG),![1300](https://pic.leetcode-cn.com/Figures/474_Ones_ZeroesSlide10.PNG),![1300](https://pic.leetcode-cn.com/Figures/474_Ones_ZeroesSlide11.PNG),![1300](https://pic.leetcode-cn.com/Figures/474_Ones_ZeroesSlide12.PNG),![1300](https://pic.leetcode-cn.com/Figures/474_Ones_ZeroesSlide13.PNG),![1300](https://pic.leetcode-cn.com/Figures/474_Ones_ZeroesSlide14.PNG),![1300](https://pic.leetcode-cn.com/Figures/474_Ones_ZeroesSlide15.PNG),![1300](https://pic.leetcode-cn.com/Figures/474_Ones_ZeroesSlide16.PNG),![1300](https://pic.leetcode-cn.com/Figures/474_Ones_ZeroesSlide17.PNG),![1300](https://pic.leetcode-cn.com/Figures/474_Ones_ZeroesSlide18.PNG),![1300](https://pic.leetcode-cn.com/Figures/474_Ones_ZeroesSlide19.PNG),![1300](https://pic.leetcode-cn.com/Figures/474_Ones_ZeroesSlide20.PNG)>

```Java [sol1]
public class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int[][] dp = new int[m + 1][n + 1];
        for (String s: strs) {
            int[] count = countzeroesones(s);
            for (int zeroes = m; zeroes >= count[0]; zeroes--)
                for (int ones = n; ones >= count[1]; ones--)
                    dp[zeroes][ones] = Math.max(1 + dp[zeroes - count[0]][ones - count[1]], dp[zeroes][ones]);
        }
        return dp[m][n];
    }
    public int[] countzeroesones(String s) {
        int[] c = new int[2];
        for (int i = 0; i < s.length(); i++) {
            c[s.charAt(i)-'0']++;
        }
        return c;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(mnl)$，其中 $l$ 是字符串的个数。

* 空间复杂度：$O(mn)$。