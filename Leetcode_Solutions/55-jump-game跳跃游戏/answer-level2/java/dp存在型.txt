### 解题思路
存在型动态规划

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        boolean[] dp = new boolean[nums.length];
        dp[0] = true;
        for (int i = 1; i < dp.length; i++) {
            for (int j = 0; j < i; j++) {
                if(dp[j] && nums[j] >= i - j){
                    dp[i] = true;
                }
            }
        }
        return dp[nums.length - 1];
    }
}
```