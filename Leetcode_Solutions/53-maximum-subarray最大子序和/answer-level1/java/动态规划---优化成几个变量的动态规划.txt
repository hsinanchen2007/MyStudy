```
class Solution {
    public int maxSubArray(int[] nums) {
        // 这类题就是套路，其实是分类，枚举以nums[i]结尾的子数组最大和，并寻求递推关系，
        // 也就是找到所谓的动态规划转移方程
        // 显然：if (dp[i-1] <= 0) dp[i] = nums[i]
        //       else dp[i] = dp[i-1] + nums[i]
        /*
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        int res = dp[0];
        for(int i = 1; i < nums.length; i++){
            dp[i] = (dp[i-1] <= 0) ? nums[i] : (dp[i-1] + nums[i]);
            res = (res > dp[i]) ? res : dp[i];
        }
        return res;
        */
        // 对上面代码进行优化，显然可以把dp这个数组用变量代替的哦
        int dp = nums[0];
        int res = nums[0];
        for(int i = 1; i < nums.length; i++){
            dp = dp <= 0 ? nums[i] : (dp + nums[i]);
            res = res > dp ? res : dp;
        }
        return res;
    }
}
```
