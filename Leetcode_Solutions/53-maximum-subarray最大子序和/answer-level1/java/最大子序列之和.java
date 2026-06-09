### 解题思路
设dp[i] 为包含 nums[i] 的最大子序列的和，如果dp[i] 小于 0 则，num[i] 本身即为最大子序列的和，相反需要加上 dp[i-1] ,最好找出dp[i] 最大值即可 

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int lenth = nums.length;
        int[] dp = new int[lenth];
        dp[0] = nums[0];
        for (int i = 1; i < lenth; i++){
            if ( dp[i-1] >=0 ){
                dp[i] = dp[i-1] +  nums[i];
            } else if(dp[i-1] <0){
                dp[i] = nums[i];
            }
        }
        for (int i = 1; i < lenth; i++){
            if (dp[i] < dp[i-1]){
                dp[i] = dp[i-1];
            }
        }
        return dp[lenth-1];
    }
}
```