### 解题思路
此处撰写解题思路
    dp[n] = Max(dp[n - 1], dp[n - 2] + nums[n], dp[n - 3] + nums[i])
### 代码

```java
class Solution {
    public static int rob(int[] nums) {
        int[] dp = new int[nums.length + 1];
        dp[0] = 0;
        for(int i = 1; i <= nums.length; i++){
            int max = Integer.MIN_VALUE;
            if(i - 3 >= 0){
                max = max > dp[i - 3] + nums[i - 1] ? max : dp[i - 3] + nums[i - 1];
            }else{
                max = max > nums[i - 1] ? max : nums[i - 1];
            }
            if(i - 2 >= 0){
                max = max > dp[i - 2] + nums[i - 1] ? max : dp[i - 2] + nums[i - 1];
            }else{
                max = max > nums[i - 1] ? max : nums[i - 1];
            }
            if(i - 1 >= 0){
                max = max > dp[i - 1] ? max : dp[i - 1];
            }
            dp[i] = max;
        }
        return dp[nums.length];
    }
}
```
这边空间复杂度可以继续优化下 不需要使用O(N)的空间复杂度 可以使用O(1)的辅助空间 然后if else的分支可以优化下少跑一点
 