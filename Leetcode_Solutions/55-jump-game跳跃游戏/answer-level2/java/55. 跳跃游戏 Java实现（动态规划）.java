### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
        public boolean canJump(int[] nums) {
            boolean[] dp = new boolean[nums.length];
            dp[nums.length - 1] = true;
            for (int i = nums.length - 2; i > -1; i--) {
                int idxLim = nums[i] + i;
                if (idxLim >= nums.length) {
                    idxLim = nums.length - 1;
                }
                dp[i] = false;
                for (int j = idxLim; j > i; j--) {
                    if (dp[j]) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            return dp[0];
        }
}
```