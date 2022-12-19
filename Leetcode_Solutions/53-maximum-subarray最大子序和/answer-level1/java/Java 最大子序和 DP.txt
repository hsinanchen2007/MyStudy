### 解题思路
常规思路
dp数组中dp[i]代表前i个位置可以得到的最大子序和
### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        if(nums == null || nums.length == 0) return 0 ;
        int n = nums.length ;
        int[] dp = new int[n] ;
        dp[0] = nums[0] ;
        for(int i = 1 ; i < n ; i++){
            dp[i] = Math.max(nums[i],nums[i]+dp[i-1]) ;
        }
        Arrays.sort(dp) ;
        return dp[n-1] ;
    }
}
```