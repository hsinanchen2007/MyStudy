### 解题思路
dp

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        if (nums.length == 0)
            return 0 ;
        
        if (nums.length == 1)
            return nums[0] ;

        if (nums.length == 2)
            return Math.max(nums[0],nums[1]) ;
        int[] dp = new int[nums.length] ;
        int ret = 0 ;

        for (int i=0 ; i < nums.length ; i++) {
            dp[i] = Math.max(i < 2 ? 0 : dp[i-2] , i < 3 ? 0 : dp[i-3] ) + nums[i] ;
            ret = Math.max(ret,dp[i]) ;
        }
        return ret ;
    }
}
```