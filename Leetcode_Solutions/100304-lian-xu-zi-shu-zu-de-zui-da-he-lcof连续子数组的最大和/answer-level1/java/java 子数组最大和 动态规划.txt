### 解题思路
此处撰写解题思路

### 代码

```java
//动态规划算法
class Solution {
    public int maxSubArray(int[] nums) {
        if(nums==null || nums.length==0){
            return 0;
        }
        //动态数组dp[i]代表以nums[i]结尾的最大连续子数组和
        int []dp= new int[nums.length];
        //初始化dp数组
        dp[0]=nums[0];
        int max=dp[0];
        for(int i = 1; i < nums.length; i++) {
            //如果前i-1的最大子数组和为整数，则当前i的最大连续子数组和为nums[i]+dp[i-1]，否则为nums[i]
            if(dp[i-1]>0){
                dp[i]=nums[i]+dp[i-1];
            }else{
                dp[i]=nums[i];
            }
            max=Math.max(max,dp[i]);
            
        }
        return max;

        
    }
}
```