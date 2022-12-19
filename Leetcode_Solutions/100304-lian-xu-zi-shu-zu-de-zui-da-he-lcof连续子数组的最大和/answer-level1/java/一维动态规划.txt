### 解题思路
#### 定义状态：dp[i]表示原数组中下标前i的数组成的子数组最大和。
#### 转态转移方程：找dp[i]与dp[i-1]的关系

注意：dp[i]是表示下标在i时的子数组的最大和，最后一项不一定是所有dp中的最大值。
         

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
         //定义状态：dp[i]表示原数组中下标前i的数组成的子数组最大和。
         int len = nums.length;
         int[] dp = new int[len];
         //初始条件
         dp[0] = nums[0];
         int max = nums[0];
         for(int i = 1; i < len; i ++){
             //前后状态间的关系
             dp[i] = Math.max(dp[i-1]+nums[i],nums[i]);
             //找dp中的最大值，注意dp[len-1]不是最大值。
             if(max < dp[i]){
                 max = dp[i];
             }
         }
         return max;
    }
}
```