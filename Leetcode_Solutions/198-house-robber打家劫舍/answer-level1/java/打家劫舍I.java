### 解题思路
转换成选与不选的问题，也就是动态规划，尤其要注意特殊情况（数组长度为0、1、2）

### 代码

```java
class Solution {
    public int rob(int[] nums) { 
        int len = nums.length;
		if (len == 0) {
			return 0;
		}
		if (len == 1) {
			return nums[0];
		}
		if (len == 2) {
			return Math.max(nums[0], nums[1]);
		}
		int[] dp = new int[len];
		dp[0] = nums[0];
		dp[1] = Math.max(nums[0], nums[1]);
		for (int i = 2; i <= len - 1; i++) {
			dp[i] = Math.max(nums[i] + dp[i - 2], dp[i - 1]);//动态规划核心部分
		}
		return dp[len - 1];
    }  
}
```