思路：
- 使用dp[] 数组来记录当前格子是否可达
- dp[i]到dp[i+k](k=nums[i])状态的更新由nums[i]的数值k，以及dp[i]是否可达来确定，如果dp[i] == true 那么dp数组[i+1, i+k+1]的值都更新为true
- 结果根据dp[len-1] 的值来确定

```
class Solution {
    public boolean canJump(int[] nums) {
        int len = nums.length;
        if(len == 0) return true;
        boolean[] dp = new boolean[len];
        dp[0] = true;

        for(int i = 0; i < len; i++) {
            if(dp[i]) {
                for(int j = 0; j < nums[i] &&  i+j+1 < len; j++) {
                    dp[i+j+1] = true;
                }
            }
        }
        return dp[len-1];

    }
}
```
