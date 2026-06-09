### 解题思路
对于数组中的每一个元素都有两种选择，选或不选。因此最初的想法就是暴力递归，但仔细分析这种方法可以很快发现复杂度是$O(2^n)$，really Bad，想想就好。
像这种问题由多个相互联系的阶段构成，可以采用大事化小、小事化了的动态规划思路。那么此时的关键点就是寻找状态转移方程，令dp[i]为前i个算上i的最长上升子序列，那么有如下的状态转移：dp[i]=max(dp[j] + 1), j < i.

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] dp = new int[nums.length];
        Arrays.fill(dp, 1);
        for (int i = 1; i < nums.length; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }
        int max = 0;
        for (int i = 0; i < nums.length; ++i) {
            max = Math.max(max, dp[i]);
        }
        return max;
    }
}
```