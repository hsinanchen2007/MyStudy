### 解题思路
dp 入注解

### 代码

```java
class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0 ;
        for (int i=0 ; i < nums.length ; i++) {
            sum += nums[i] ;
        }
        if (sum % 2 == 1)
            return false ;
        int target = sum / 2 ;
        // dp[i] 表示 i数是否可以通过nums数组达到
        boolean[] dp = new boolean[target+1] ;
        Arrays.fill(dp,false) ;
        dp[0] = true ;
        for (int i=0 ; i< nums.length ; i++) {
            if (nums[i] > target)
                continue ;
            // 从后向前遍历是为了防止 nums[i]被重复使用 。
            for (int j=target ; j >= nums[i]  ; j--) {
                if (dp[target] == true)
                    return true ;
                if (dp[j-nums[i]]==true) 
                    dp[j] = true ;
            }
        } 
        return dp[target] ;
    }
}
```