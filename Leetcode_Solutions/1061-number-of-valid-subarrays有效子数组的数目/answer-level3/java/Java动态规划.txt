```
class Solution {
        public int validSubarrays(int[] nums) {
        int length = nums.length;
        int[] dp=new int[length];
         Arrays.fill(dp, 1);
        int ans=1;
        for(int i=length-2;i>=0;--i){
            int j=i+1;
            while(j<length&&nums[i]<=nums[j]){
                j+=dp[j];
            }
            dp[i]=j-i;
            ans+=dp[i];
        }
        return ans;
    }
}

```
