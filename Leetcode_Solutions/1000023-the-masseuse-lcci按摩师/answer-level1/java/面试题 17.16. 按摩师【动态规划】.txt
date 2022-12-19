### 解题思路
    动态规划，今天只和昨天的状态相关，可考虑两种情况：
    (1)今天不接受预约：那么昨天不接受预约，或接受了预约，取二者最大值，即：dp[i][0] = max(dp[i - 1][0], dp[i - 1][1])；
    (2)今天接受预约：只需要从昨天不接受预约转移而来，加上今天的时常dp[i][1] = dp[i - 1][0] + nums[i]。
    综合考虑，可得到递推方程：dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])

### 代码

```java
class Solution {
    public int massage(int[] nums) {
        int dp0 = 0,dp1 = 0;
        for(int i=0;i<nums.length;i++){
            int dp = Math.max(dp1,dp0+nums[i]);
            dp0 = dp1;
            dp1 = dp;
        }
        return dp1;

    }
}
```