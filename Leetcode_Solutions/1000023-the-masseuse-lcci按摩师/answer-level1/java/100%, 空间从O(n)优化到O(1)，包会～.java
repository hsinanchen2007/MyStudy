// 🙋 我来咯，打卡！**求赞求赞～**

// 递推方程：`dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]`

// 1. 空间 $O(n)$
// ```Java []
class Solution {
    public int massage(int[] nums) {
        int n = nums.length;
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        int[] dp = new int[n];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
}
// ```

// 2. 空间优化到 $O(1)$
// ```Java []
class Solution {
    public int massage(int[] nums) {
        int a = 0, b = 0;
        for (int i = 0; i < nums.length; i++) {
            int c = Math.max(b, a + nums[i]);
            a = b;
            b = c;
        }
        return b;
    }
}
// ```


// 和[198. 打家劫舍](https://leetcode-cn.com/problems/house-robber/)是一模一样的重题，小偷系列一共三道都可以做做（198 213 337）