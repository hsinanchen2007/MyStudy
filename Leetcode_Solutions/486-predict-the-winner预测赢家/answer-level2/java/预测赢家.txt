#### 方法一：递归

我们可以使用递归的方式枚举出所有的情况。在先手选择了数 `x` 时，我们可以将当前的和增加 `x`，而在后手选择了数 `y` 时，我们可以将当前的和减去 `x`，这样先手胜利当且仅当最后的和大于等于 `0`。

假设当前剩下的数为 `nums[s .. e]`，并且是先手的轮次。那么先手可以选择 `nums[s]` 或者 `nums[e]`，并把当前的和对应增加 `nums[s]` 或者 `nums[e]`，并交给后手选数。由于先手会选择最优的玩法，因此它会选择 `nums[s] + winner(s + 1, e)` 与 `nums[e] + winner(s, e - 1)` 中的较大值，其中 `winner(l, r)` 表示剩下的数为 `nums[l .. r]` 时，先手最多可以获得的分数。

![Recursive_Tree](https://pic.leetcode-cn.com/Figures/486/486_Predict_the_winner_new.PNG){:width=480}

```Java [sol1]
public class Solution {
    public boolean PredictTheWinner(int[] nums) {
        return winner(nums, 0, nums.length - 1, 1) >= 0;
    }
    public int winner(int[] nums, int s, int e, int turn) {
        if (s == e)
            return turn * nums[s];
        int a = turn * nums[s] + winner(nums, s + 1, e, -turn);
        int b = turn * nums[e] + winner(nums, s, e - 1, -turn);
        return turn * Math.max(turn * a, turn * b);
    }
}
```

**复杂度分析**

* 时间复杂度：$O(2^N)$，其中 $N$ 是数组的长度。

* 空间复杂度：$O(N)$，为递归时栈使用的空间。

#### 方法二：动态规划

我们同样可以使用动态规划来解决这个问题。用 `dp(i, j)` 表示当剩下的数为 `nums[i .. j]` 时，当前操作的选手（注意，不一定是先手）与另一位选手最多的分数差。当前操作的选手可以选择 `nums[i]` 并留下 `nums[i+1 .. j]`，或选择 `nums[j]` 并留下 `nums[i .. j-1]`，因此状态转移方程为：

```
dp(i, j) = max(nums[i] - dp(i+1, j), nums[j] - dp(i, j-1))
dp(i, i) = nums[i]
```

如果 `dp(0, n - 1) >= 0`，那么先手必胜。

<![1000](https://pic.leetcode-cn.com/Figures/486/486_Predict_the_winnerSlide1.PNG),![1000](https://pic.leetcode-cn.com/Figures/486/486_Predict_the_winnerSlide2.PNG),![1000](https://pic.leetcode-cn.com/Figures/486/486_Predict_the_winnerSlide3.PNG),![1000](https://pic.leetcode-cn.com/Figures/486/486_Predict_the_winnerSlide4.PNG),![1000](https://pic.leetcode-cn.com/Figures/486/486_Predict_the_winnerSlide5.PNG),![1000](https://pic.leetcode-cn.com/Figures/486/486_Predict_the_winnerSlide6.PNG),![1000](https://pic.leetcode-cn.com/Figures/486/486_Predict_the_winnerSlide7.PNG),![1000](https://pic.leetcode-cn.com/Figures/486/486_Predict_the_winnerSlide8.PNG),![1000](https://pic.leetcode-cn.com/Figures/486/486_Predict_the_winnerSlide9.PNG),![1000](https://pic.leetcode-cn.com/Figures/486/486_Predict_the_winnerSlide10.PNG),![1000](https://pic.leetcode-cn.com/Figures/486/486_Predict_the_winnerSlide11.PNG),![1000](https://pic.leetcode-cn.com/Figures/486/486_Predict_the_winnerSlide12.PNG)>

```Java [sol2]
public class Solution {
    public boolean PredictTheWinner(int[] nums) {
        int[][] dp = new int[nums.length + 1][nums.length];
        for (int s = nums.length; s >= 0; s--) {
            for (int e = s + 1; e < nums.length; e++) {
                int a = nums[s] - dp[s + 1][e];
                int b = nums[e] - dp[s][e - 1];
                dp[s][e] = Math.max(a, b);
            }
        }
        return dp[0][nums.length - 1] >= 0;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N^2)$，其中 $N$ 是数组的长度。

* 空间复杂度：$O(N^2)$。

#### 方法三：动态规划 + 空间优化

对于方法二中动态规划的状态转移方程，我们发现 `dp(i, j)` 只和 `dp(i+1, j)` 和 `dp(i, j-1)` 有关，即在计算第 `i` 行的 `dp` 值时，只有该行与第 `i + 1` 行是有用的。因此我们可以将空间优化至一维。

```Java [sol3]
public class Solution {
    public boolean PredictTheWinner(int[] nums) {
        int[] dp = new int[nums.length];
        for (int s = nums.length; s >= 0; s--) {
            for (int e = s + 1; e < nums.length; e++) {
                int a = nums[s] - dp[e];
                int b = nums[e] - dp[e - 1];
                dp[e] = Math.max(a, b);
            }
        }
        return dp[nums.length - 1] >= 0;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N^2)$，其中 $N$ 是数组的长度。

* 空间复杂度：$O(N)$。