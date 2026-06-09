### 解题思路
比较典型的动态规划题（一般来说，涉及最大最小等极值的情况，都可以朝动态规划去靠，再一个就考虑目标问题是否可以由子问题推导）
本题中，状态转移方程可以考虑为dp[n]表示数组中到第n个数字的最长摆动序列长度，那么这个序列最后一个差值就可能是负数或者正数两种情况，所以一维的状态转移方程不能清楚的表示子问题的状态，需要再加一个维度，dp[n][m]，m表示最后一个差值的状态，0表示为负数，1表示为正数，那么状态转移方程就出来了
差值为负数
dp[n][0] = max(dp[n-1][1]+1, dp[n-1][0]);
差值为正数
dp[n][1] = max(dp[n-1][0]+1, dp[n-1][1]);
当差值为0时，维持上一个数的状态，即:
dp[n][0] = dp[n-1][0];
dp[n][1] = dp[n-1][1];

注意一点就是由于是两个数的差值，我们这里只算了一个数，所以后面需要把第一个数加进来，可以在dp初始化时全部置为1，也可以在循环中处理一下，还可以在最后加上（本题采用的是这种方法），反正意思理解了就行

### 代码

```java
class Solution {
    public int wiggleMaxLength(int[] nums) {
        if(nums == null || nums.length < 2) {
			return nums == null ? 0 : nums.length;
		}
		int[][] dp = new int[nums.length+1][2];
		
		for(int i=1; i<nums.length; i++) {
			if(nums[i] - nums[i-1] > 0) {
				dp[i+1][1] = Math.max(dp[i][0]+1, dp[i][1]);
			}else if(nums[i] - nums[i-1] < 0) {
				dp[i+1][0] = Math.max(dp[i][1]+1, dp[i][0]);
			}else {
				dp[i+1][1] = dp[i][1];
				dp[i+1][0] = dp[i][0];
			}
		}
		return Math.max(dp[dp.length-1][1], dp[dp.length-1][0])+1;
    }
}
```