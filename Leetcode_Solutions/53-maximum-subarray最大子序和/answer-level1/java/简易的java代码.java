### 代码

```java
class Solution {
    public int maxSubArray(int[] nums){
		/*
		 * dp[i]表示以nums[i]结尾的子数组的最大和
		 * 状态转移方程：dp[i] = Math.max(dp[i-1]+nums[i],nums[i])
		 */
		int size = nums.length;
		if(size == 0){
			return 0;
		}
		int[] dp = new int[size];
		int max = nums[0];// 记录子数组的最大和
		for(int i=0;i<nums.length;i++){
			if(i == 0){
				dp[i] = nums[i];
				continue;
			}
			dp[i] = Math.max(dp[i-1]+nums[i], nums[i]);
			max = Math.max(max,dp[i]);
		}
		return max;
	}
}
```

### 性能表现

![1.png](https://pic.leetcode-cn.com/1132b1096e4a5205342aef0f2cad3bf3362c500f7be2280f0a6911b08b3441f9-1.png)

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/57798294d3fdba3072252a65d046e18b8e8dd0921c624deb3603f961a5721ce1-wechat.png)

