### 代码

```java
class Solution {
    public int rob(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        if (nums.length == 1) {
            return nums[0];
        }
        if (nums.length == 2) {
            return Math.max(nums[0], nums[1]);
        }
        return Math.max(rob(nums, 0, nums.length - 1), rob(nums, 1, nums.length));
    }

    private int rob(int[] nums, int s, int length) {
        int[] dp = new int[length - s];
        dp[0] = nums[s];
        dp[1] = Math.max(nums[s], nums[s+1]);

        for (int i = s+2; i < length; ++i) {
            dp[i-s] = Math.max(dp[i-2-s] + nums[i], dp[i-1-s]);
        }
        return dp[length-s-1];
    }
}
```