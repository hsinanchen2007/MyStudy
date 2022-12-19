### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }

        if (nums.length == 1) {
            return nums[0];
        }
        
        if(nums.length == 2) {
            return Math.max(nums[0], nums[1]);
        }

        int len = nums.length;
        int[] dp = new int[len - 1];
        int max = 0;

        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        for (int i = 2; i < len - 1; i++) {
            dp[i] = Math.max(dp[(i - 1)], dp[(i - 2)] + nums[i]);
        }
        max = dp[dp.length - 1];

        dp[0] = nums[1];
        dp[1] = Math.max(nums[1], nums[2]);
        for (int i = 2; i < len - 1; i++) {
            dp[i] = Math.max(dp[(i - 1)], dp[(i - 2)] + nums[i + 1]);
        }

        return Math.max(max, dp[dp.length - 1]);
    }
}
```