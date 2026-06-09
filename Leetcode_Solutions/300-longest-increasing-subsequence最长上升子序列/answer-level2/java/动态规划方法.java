# 动态规划算法
时间复杂度O(n^2),空间复杂度O(n)
```java []
class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums.length==0) return 0;
        if(nums.length==1) return 1;
        int max_val=1;
        int L=nums.length;
        int[] dp=new int[L];
        Arrays.fill(dp,1);
        for(int i=1;i<L;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]) dp[i]=Math.max(dp[j]+1,dp[i]);
            }
            max_val=Math.max(dp[i],max_val);
        }
        return max_val;
    }
}
```

