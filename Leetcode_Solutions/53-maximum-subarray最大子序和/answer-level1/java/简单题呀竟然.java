### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        if(nums==null || nums.length==0)
			return -1;
		
		int n = nums.length;
		int[] dp = new int[n];
		
		dp[0] = nums[0]; //dp数组表示以此下标结尾的子序列和的最大值
		
		int out = dp[0];
		for (int i = 1; i < nums.length; i++) {
			dp[i] = Math.max(dp[i-1] + nums[i], nums[i]);
			out = Math.max(dp[i], out);
		}
		return out;
    }
}
```
![image.png](https://pic.leetcode-cn.com/4531e9b63c114bc4d18b540e8dbf1e0e39605b0210f35ba30e60703367e9fa2d-image.png)
