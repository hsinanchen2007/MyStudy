### 解题思路
动态规划：
dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i - 1]);
需要注意的是第i个预约的时长在nums[i - 1]，因为dp数组下标和nums下标差1！！！！（为了解决刚开始的越界问题）

### 代码

```java
class Solution {
    public int massage(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        // if (nums.length == 1) {
        //     return nums[0];
        // }
        int[] dp = new int[nums.length + 1];
        dp[1] = nums[0];
        int max = nums[0];
        for (int i = 2; i <= nums.length; i++) {
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i - 1]);
            max = Math.max(dp[i], max);
        }

        return max;
    }
}
```