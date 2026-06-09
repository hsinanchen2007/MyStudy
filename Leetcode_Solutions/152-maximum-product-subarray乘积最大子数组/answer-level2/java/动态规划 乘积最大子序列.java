```
class Solution {
    public int maxProduct(int[] nums) {
        //dp[i] 表示以第i个结尾的序列的最大乘积
        int[] dp = new int[nums.length];       
        dp[0] = nums[0];
        //记录以i-1结尾时，序列乘积的最小值和最大值
        int premax=nums[0];
        int premin=nums[0];
        int res=nums[0];
        for(int i=1; i< nums.length; i++){
            //通过i-1时的值，计算i时的最大值和最小值
            int min=Math.min(Math.min(nums[i],premin*nums[i]),premax*nums[i]);
            int max=Math.max(Math.max(nums[i],premax*nums[i]),premin*nums[i]);
            //dp[i]记录i结尾时的最大值
            dp[i]=max;
            res = Math.max(res,dp[i]);
            //再直接return res
            //更新premin，premax
            premin=min;
            premax=max;
        }
        //根据dp定义，遍历dp求最大 可由上面注释掉的代替
        //int res=dp[0];
        //for(int i=1;i<nums.length;i++){
          //  res=Math.max(dp[i],res);
       // }
        return res;
    }
}
```
