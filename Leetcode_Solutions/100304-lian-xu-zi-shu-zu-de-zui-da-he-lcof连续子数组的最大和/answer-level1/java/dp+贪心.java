### 解题思路
此题有四种方法，暴力，dp，贪心和分治
对于dp来说，设dp[i]是nums[i]的最大值，则有dp[i] = max(i,dp[i-1] + i)
对于贪心来说，定义两个值，一个是迄今为止最大的和，一个是当前元素最大的和。
### 代码

```java
class Solution {
    // 最大子序和问题，可以用两层for循环，dp，分治和贪心来做

    public int maxSubArray(int[] nums) {
        // dp[i]表示在nums[i]的最大值
        // dp[i] = max(i,dp[i-1] + i)
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        int max = dp[0];
        for(int i = 1; i < nums.length; i++) {
            dp[i] = Math.max(nums[i], dp[i-1] + nums[i]);
            max = Math.max(max, dp[i]);
        }
        return max;
    }


    // 贪心：定义两个元素，一个是迄今为止最大的和，一个是当前元素最大的和
    public int maxSubArray(int[] nums) {
        int sum = nums[0], temp = 0;
        for(int i = 0; i < nums.length; i++) {
            if(temp > 0) temp += nums[i];
            else temp = nums[i];
            sum = Math.max(sum, temp);
        }
        return sum;
    }
}
```