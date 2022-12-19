public class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        int[] dp = new int[nums.length + 1];
        dp[0] = 0;
        for (int i = 1; i <= nums.length; i++) {
            if (sum % 2 == 0) {
                if (nums[i - 1] % 2 == 0) {
                    if ((sum - nums[i - 1]) / 2 == dp[i - 1]) {
                        return i - 1;
                    }
                }
            } else {
                if (nums[i - 1] % 2 != 0) {
                    if ((sum - nums[i - 1]) / 2 == dp[i - 1]) {
                        return i - 1;
                    }
                }
            }
            dp[i] = dp[i - 1] + nums[i - 1];
        }
        return -1;
    }
}