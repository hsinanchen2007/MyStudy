### 解题思路
* 定义 $dp[i]$ 为抢劫 $0..i$ 个 house 的最大收益
* 对于第 i 个 house, 只有两种可能性：**抢或者不抢**, 当选择抢劫第 i 个时，则**不能**抢第 i - 1 个, 所以   recurrence formula: $dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])$


### 代码

```java
class Solution {
    public int rob(int[] nums) {
        // 特殊情况处理
        if (nums == null || nums.length == 0) {
            return 0;
        }

        int N = nums.length;
        int[] dp = new int[N + 1];
        // base case: dp[0] = 0, dp[1] = nums[0]
        dp[1] = nums[0];
        for (int i = 2; i <= N; i++) {
            dp[i] = Math.max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }

        return dp[N];
    }
}

// 可以发现实际上 dp[i] 只依赖于 dp[i - 1] 和 dp[i - 2], 所以我们最多需要记住前两个数字就够了
// 这样空间复杂度可以从 n 降到 1
class Solution {
    public int rob(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }

        int prevMax = 0, currMax = nums[0];
        for (int i = 1; i < nums.length; i++) {
            int nextPrev = currMax;
            currMax = Math.max(prevMax + nums[i], currMax);
            prevMax = nextPrev;
        }

        return currMax;
    }
}
```