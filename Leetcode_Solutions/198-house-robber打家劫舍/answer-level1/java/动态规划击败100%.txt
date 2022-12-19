### 解题思路
F(n) = MAX(F(n-1),F(n-2)+nums[n]);
当只有一个数时，显然答案为nums[0]
当只有两个数时，答案为Max(nums[0],nums[1])
当有三个数时，此时nums[2]若选取则只能加上F(0)，或者是不选择num[2]而选择F(1)


### 代码

```java
class Solution {
    public int rob(int[] nums) {
        if(nums.length == 0)
            return 0;
        if(nums.length == 1)
            return nums[0];
        double res = 0;
        double[] dp = new double[nums.length];
        
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0],nums[1]);
        for(int i = 2;i<nums.length;i++){
            dp[i] = Math.max(dp[i-1],dp[i-2]+nums[i]);
        }
        return (int)dp[nums.length - 1];
    }
}
```