### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int massage(int[] nums) {
        int size = nums.length;
        if(size == 0)
            return 0;
        if(size == 1)
            return nums[0];
        int[] dp = new int[size];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        for(int i=2; i<size; i++) {
            // dp[i]代表的是，[0...i]的最优解，i点如果接客，即i-1不能接，为dp[i-2]+nums[i],不接则为dp[i-1]
            dp[i] = Math.max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[size-1];
    }
}
```