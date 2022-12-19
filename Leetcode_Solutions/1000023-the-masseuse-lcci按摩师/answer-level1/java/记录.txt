### 解题思路
思路和官方思路一致，设定二维数组，记录每一步变化的最优值，每一步分为使用和不使用两种情况根据不同情况
给出不同状态转移方程

### 代码

```java
class Solution {
    public int massage(int[] nums) {
        int ans= 0;
        if (nums.length==0)
            return 0;
        int[][] dp = new int[nums.length][2];
        dp[0][0]=0;
        dp[0][1]=nums[0];
        for (int i = 1; i <nums.length; i++) {
            dp[i][0]=Math.max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = dp[i-1][0]+nums[i];
        }
        ans = Math.max(dp[nums.length-1][0],dp[nums.length-1][1]);
        return ans;
    }
}
```