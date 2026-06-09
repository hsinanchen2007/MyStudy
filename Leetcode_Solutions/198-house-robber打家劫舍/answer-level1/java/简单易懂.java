```
class Solution {
    public int rob(int[] nums) {
        // int prevMax=0;
        // int currMax=0;
        // for(int num:nums){
        //     int temp = currMax;
        //     currMax=Math.max(prevMax+num,currMax);
        //     prevMax=temp;
        // }
        // return currMax;

        int n=nums.length;
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        int[] dp = new int[n];
        dp[0]=nums[0];
        dp[1]=Math.max(dp[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=Math.max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
}
```
