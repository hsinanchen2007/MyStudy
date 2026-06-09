### 解题思路
考虑两种情况，不抢第一家和不抢最后一家

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        int len = nums.length;
        if (len == 0) return 0; 
        if (len == 1) return nums[0];
        int[][] dp = new int[len][2];
        dp[1][0] = 0;
        dp[1][1] = nums[1]; 
        for (int i = 2; i < len; i++) {
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        int res1 = Math.max(dp[len - 1][0], dp[len - 1][1]);
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for (int i = 1; i < len - 1; i++) {
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        int res2 = Math.max(dp[len - 2][0], dp[len - 2][1]);
        return Math.max(res1, res2);
    }
}
```