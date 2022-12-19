### 解题思路
设盗第x家的最大价值为f(x)，则f(x)=max{nums[x]+f(x-2), f(x-1)}

### 代码

```java
class Solution {
    public int rob(int[] nums) {
		int len = nums.length;
		if (len == 0) return 0;
        else if (len == 1) return nums[0];
        else if (len == 2) return Math.max(nums[0], nums[1]);
        else {
            int[] dp = new int[len];
            dp[0] = nums[0];
            dp[1] = Math.max(nums[0], nums[1]);
            for (int i = 2; i < len; i++) {
                dp[i] = Math.max(nums[i] + dp[i-2], dp[i -1]);
            }
            return dp[len-1];
        }
	}
}
```