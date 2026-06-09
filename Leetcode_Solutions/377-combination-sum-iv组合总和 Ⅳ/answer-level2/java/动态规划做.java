### 解题思路
动态规划。


### 代码

```java
class Solution {
    public int combinationSum4(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        
        int[] dp = new int[target + 1];
        int len = nums.length;
        dp[0] = 1;
        for (int i = 1; i < dp.length; i++) {
            dp[i] = 0;
            for (int j = 0; j < len; j++) {
                if(i - nums[j] >= 0){
                    dp[i] += dp[i - nums[j]];
                }
            }
        }

        return dp[target];
    }
}
```