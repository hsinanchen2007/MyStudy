### 解题思路
定义dp[i][0] 表示考虑前 i个预约不接的最长预约时间，dp[i][1] 表示考虑前 i个预约接的最长预约时间。
从前往后计算 dp值，假设我们已经计算出前i−1 个dp 值，考虑计算dp[i][0/1] 的答案。
首先考虑dp[i][0] 的转移方程，由于这个状态下第 i 个预约是不接的，所以第i−1 个预约接或不接都可以，故可以从dp[i−1][0] 和dp[i−1][1] 两个状态转移过来，转移方程即为：
dp[i][0]=max(dp[i-1][0], dp[i-1][1])。
对于 dp[i][1] ，由于这个状态下第 i 个预约要接，根据题目要求按摩师不能接受相邻的预约，所以第i−1 个预约不能接受，故我们只能从dp[i−1][0] 这个状态转移过来，转移方程即为：
dp[i][1]=dp[i−1][0]+nums[i]。
最后答案即为max(dp[n][0], dp[n][1]) ，其中 n表示预约的个数。
再回来看转移方程，我们发现计算dp[i][0/1] 时，只与前一个状态dp[i−1][0/1] 有关，所以我们可以不用开数组，只用两个变量dp0,dp1即可。
### 代码

```java
class Solution {
    public int massage(int[] nums) {
        if (0 == nums.length) {
            return 0;
        }
        int dp0 = 0;//不接
        int dp1 = nums[0];//接
        int temp = 0;
        for (int i = 1; i < nums.length; i++) {
            temp = dp0;
            dp0 = Math.max(temp, dp1);
            dp1 = temp + nums[i];
        }
        
        return Math.max(dp0, dp1);
    }
}
```