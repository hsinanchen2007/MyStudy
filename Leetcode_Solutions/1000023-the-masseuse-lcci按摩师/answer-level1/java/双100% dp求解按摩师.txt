### 自底向上的DP
dp[i] 表示前nums[0],nums[1],...,nums[i-1]的最大预约时间；
**则怎么求dp[i+1]???**
***dp[i+1] = max(dp[i], max(dp[0],dp[1],...,dp[i-1]) + nums[i]);***
求解dp[i+1]的时候，对于dp[0],dp[1],...,dp[i-1]，其都可以再预约nums[i],但是dp[i]因为相邻，不能预约nums[i]
因此他们的最大值即为，dp[i+1]
```java
class Solution {
    public int massage(int[] nums) {
        if(nums.length == 0){
            return 0;
        }
        int[] dp = new int[nums.length + 1];
        dp[1] = nums[0];
        for(int i = 2; i <= nums.length; i++){
            for(int j = 0; j < i-1; j++){
                dp[i] = Math.max(dp[j] + nums[i-1], dp[i]);
            }
            dp[i] = Math.max(dp[i], dp[i-1]);
        }
        return dp[nums.length];
    }
}
```
***dp[i+1] = max(dp[i], dp[i-1]+nums[i]);***
``` java
    public int massage(int[] nums) {
        if(nums.length == 0){
            return 0;
        }
        int[] dp = new int[nums.length + 1];
        dp[1] = nums[0];
        for(int i = 2; i <= nums.length; i++){
            dp[i] = Math.max(dp[i-2] + nums[i-1], dp[i-1]);
        }
        return dp[nums.length];
    }
```
    //空间优化
```java
    public int massage(int[] nums) {
        if(nums.length == 0){
            return 0;
        }
        int prepre = 0;
        int pre = 0;
        for(int i = 0; i < nums.length; i++){
            int c = Math.max(prepre + nums[i], pre);
            prepre = pre;
            pre = c;
        }
        return pre;
    }
```
