/*class Solution {
    public int maxSubArray(int[] nums) {
        int[] dp = new int[nums.length];
        int max = nums[0];
        dp[0] = nums[0];
        for(int i=1;i<nums.length;i++){
            dp[i]=Math.max(nums[i],dp[i-1]+nums[i]);
            max = Math.max(dp[i],max);
        }
        return max;
    }
}*/
class Solution {
    public int maxSubArray(int[] nums) {
        int max=nums[0];
        int tmp=nums[0];
        for(int i=1;i<nums.length;i++){
            tmp+=nums[i];
            if(tmp<nums[i]){
                tmp=nums[i];
            }
            if(max<tmp){
                max=tmp;
            }
        }
        return max;      
    }
}