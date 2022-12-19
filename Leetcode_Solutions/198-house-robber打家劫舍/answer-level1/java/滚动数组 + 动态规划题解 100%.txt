通过分析dp数组当前值只与前三个值有关
那么我们dp数组就存三个值
每次用当前index于3取模即可
不过为啥空间复杂度才击败5%？？？

```
class Solution {
    public int rob(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }

        if (nums.length == 1) {
            return nums[0];
        }

        if (nums.length == 2) {
            return Math.max(nums[0], nums[1]);
        }

        int[] dp = new int[3];
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = Math.max(dp[0] + nums[2], dp[1]); // 初始化dp数组

        for (int i = 3; i < nums.length; i ++) {
            dp[i % 3] = Math.max(dp[(i - 3) % 3] + nums[i], Math.max(dp[(i - 2) % 3] + nums[i], dp[(i - 1) % 3])); // 前三个值的state取max
        }

        return dp[(nums.length - 1) % 3];
    }
}
```
