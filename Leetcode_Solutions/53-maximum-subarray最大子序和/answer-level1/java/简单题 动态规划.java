### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
       if(nums==null || nums.length==0)
			return -1;
		
		//由于dp数组只用到前一个计算结果的值，也就是dp[i-1]的值
		int dp = nums[0];
		int max = dp;
		
		for (int i = 1; i < nums.length; i++) {
			dp = Math.max(dp + nums[i], nums[i]);
			max = Math.max(max, dp);
		}
		return max;
    }
}
```
![image.png](https://pic.leetcode-cn.com/50ae0b613b803dbf715d95ef344d9dd4521c1d8b32f5d141cb2c6cf726187acb-image.png)
