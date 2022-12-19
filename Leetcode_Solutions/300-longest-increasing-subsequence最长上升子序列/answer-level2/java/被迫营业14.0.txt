class Solution {
   public static int lengthOfLIS(int[] nums) {
	        int [] dp = new int[nums.length];
	        if(nums.length<2) {
	        	return nums.length;
	        }
	        Arrays.fill(dp, 1);
	        for (int i = 1; i < nums.length; i++) {
				for (int j = 0; j < i; j++) {
					if(nums[j]<nums[i]) {
						dp[i] = Math.max(dp[j]+1, dp[i]);
					}
				}
			}
	        Arrays.sort(dp);
	        return dp[dp.length-1];
	    }
}