### 
解题思路状态转移方程：dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i])

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        
        int dp0 = 0, dp1 = 0;
        for (int num : nums) {
            int cur = Math.max(dp0 + num, dp1);
            dp0 = dp1;
            dp1 = cur;
        }
        // dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i])

        return dp1;
    }
}
```