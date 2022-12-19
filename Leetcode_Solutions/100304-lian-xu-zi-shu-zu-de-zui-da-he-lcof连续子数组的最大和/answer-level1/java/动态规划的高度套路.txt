### 解题思路
高度套路的动态规划
https://zhuanlan.zhihu.com/p/107457744

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        if(nums==null||nums.length==0){
            return 0;
        }
        int max=nums[0];
        int[] dp=new int[nums.length];
        dp[0]=nums[0];
        if(nums.length==1){
            return nums[0];
        }
        for(int i=1;i<dp.length;i++){
            dp[i]=Math.max(nums[i],dp[i-1]+nums[i]);
            max=Math.max(dp[i],max);
        }
        return max;
    }
}
```