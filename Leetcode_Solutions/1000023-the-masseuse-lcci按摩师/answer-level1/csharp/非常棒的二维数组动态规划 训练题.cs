### 解题思路
二维数组dp[i][0]表示前i个数在不取i的情况下的最优解,dp[i][1]表示在前i个数取i的情况下的最优解。
为什么要这么做，是因为在动态规划的状态改变时，需要考虑前一个状态是否取了最后一个值i。

### 代码

```csharp
public class Solution {
    public int Massage(int[] nums) {
        if (nums.Length == 0) return 0;
        int[][] dp = new int[nums.Length + 1][];
            for (int i = 0; i < dp.Length; i++)
            {
                dp[i] = new int[2];
            }
            dp[0][0] = 0;
            dp[0][1] = 0;
            dp[1][0] = 0;
            dp[1][1] = nums[0];
            for (int i = 2; i < dp.Length; i++)
            {
                dp[i][0] = Math.Max(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = Math.Max(dp[i - 1][0] + nums[i - 1], dp[i - 1][1]);
            }
            int res = Math.Max(dp[nums.Length][0], dp[nums.Length][1]);
            return res;
    }
}
```