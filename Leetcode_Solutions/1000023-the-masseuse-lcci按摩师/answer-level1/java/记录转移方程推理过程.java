*本题题解并无新意，只做思路及推理过程记录。*
1. 寻找状态转移方程：
    不能连续预约时求dp[i]，自然可以想到dp[i]可以取dp[i-2]+nums[i],又因为dp数组始终保存当前的最优解，dp[i]的值应和dp[i-1]的进行比较
    故得dp[i] = Math.max(dp[i-2]+nums[i],dp[i-1]);
2. 考虑范围：
    - 在1中所得状态转移方程，应有范围：0≤i-1＜len && 0≤i-2＜len && 0≤i＜len 由此可得：范围2≤i＜len
    - 然后考虑0≤i＜2时，dp[0]=nums[0]无需多加思考，dp[1]应取当前最优解，故得dp[1] = Math.max(nums[0],nums[1]);
3. 考虑边界：
    在2中有dp[0]和dp[1]，故需考虑数组长度不足的情况。
    自然可得：len=0时返回0；len=1时返回第一个。

```
class Solution {
    public int massage(int[] nums) {
        int len = nums.length;
        if(len == 0)
            return 0;
        if(len == 1)
            return nums[0];
        int[] dp = new int[len];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0],nums[1]);
        
        for(int i = 2;i < len;i ++){// i>=2&&i<len
            dp[i] = Math.max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[len-1];
    }
}
```
*动态方程的两种求法：此处是自底向上*