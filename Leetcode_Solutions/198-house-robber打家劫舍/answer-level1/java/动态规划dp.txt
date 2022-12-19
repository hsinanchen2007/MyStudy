### 解题思路
定义dp[i]为选择i-3下标获取的最大利润值
状态转移方程为: dp[i+3] = Math.max(nums[i] + dp[i], nums[i] + dp[i+1]);
为满足状态方程初始条件：定义dp[0] dp[1] dp[2] 为0
注意：最后的返回值应该是最后一位结尾或者倒数第二位的大者


### 代码

```java
class Solution {
    public int rob(int[] nums) {
        //打家劫舍问题
        int[] dp = new int[nums.length + 3];
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 0;

        //一维动态dp数组
        for (int i = 0; i < nums.length; i ++) {
            dp[i+3] = Math.max(nums[i] + dp[i], nums[i] + dp[i+1]);
        }
        
        return Math.max(dp[nums.length + 2], dp[nums.length + 1]);
    }
}
```