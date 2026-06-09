用一个数组记录到i位置的最大值，并用一个m记录是否用了该位置的数。
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :37.4 MB, 在所有 Java 提交中击败了100.00%的用户
```
class Solution {
    public int massage(int[] nums) {
        if(nums.length==0) return 0;
        if(nums.length==2) return Math.max(nums[0],nums[1]);
        int[] dp = new int[nums.length];
        int[] m = new int[nums.length];
        dp[0] = nums[0];
        m[0]=1;
        for(int i=1;i<nums.length;i++){
            if(i-2>=0){
                if(m[i-1]==0){
                    if(dp[i-1]>dp[i-2]){
                        dp[i]=dp[i-1]+nums[i];
                    }else{
                        dp[i]=dp[i-2]+nums[i];
                        
                    }
                    m[i]=1;
                }else{
                    if(dp[i-1]>=dp[i-2]+nums[i]){
                        dp[i]=dp[i-1];
                    }else{
                        dp[i]=dp[i-2]+nums[i];
                        m[i]=1;
                    }
                }
            }else{
                if(nums[i]>nums[i-1]){
                    dp[i]=nums[i];
                    m[i]=1;
                }else{
                    dp[i]=nums[0];
                }
            }
        }
        return dp[nums.length-1];        
    }
}
```
