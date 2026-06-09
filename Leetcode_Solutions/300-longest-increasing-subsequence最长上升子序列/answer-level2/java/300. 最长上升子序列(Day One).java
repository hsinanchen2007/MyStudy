### 法一
动态规划，dp[i]表示以i结尾的序列长度（必须取到i），dp[i] = Max(dp[j]) + 1 {0 <= j < i && nums[i] > nums[j]}

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        if (0 == nums.length) {
            return 0;
        }
        
        int[] dp = new int[nums.length];
        dp[0] = 1;
        int max = dp[0];
        for (int i = 1; i < nums.length; i++) {
            int length = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    length = Math.max(length, dp[j]);
                }
            }
            dp[i] = length + 1;
            if (dp[i] > max) {
                max = dp[i];
            }
        }

        return max;
    }
}
```