    // dp[i] 代表字串以该字符结尾的话长度为多少
    class Solution {
        public int lengthOfLIS(int[] nums) {
            if(nums.length == 0){
                return 0;
            }
            int[] dp = new int[nums.length];
            int res = 1;
            Arrays.fill(dp, 1);
            for(int i = 1;i < nums.length;i++) {
                int max = 0;
                for(int j = i - 1;j >= 0;j--) {
                    if(nums[j] < nums[i]) {
                        max = Math.max(max, dp[j]);
                    }
                }
                dp[i] = max + 1;
                res = Math.max(res, dp[i]);
            }
            return res;
        }
    }