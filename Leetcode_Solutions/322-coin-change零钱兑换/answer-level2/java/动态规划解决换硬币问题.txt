### 解题思路
此处撰写解题思路
思想：动态规划，考虑最后一枚硬币是什么。
1. 初始化一个dp数组，有个小坑，其容量是amount+1!!!这个数组是用来标记有这么多钱，需要多少枚硬币的。
2. 将钱量从1开始遍历到amount，然后对于每个钱量，遍历每种币值（即假设这种币值是最后一枚硬币），那显然更新dp[money]显而易见了，具体可见下面代码。
### 代码

```java
class Solution {
    public int coinChange(int[] coins, int amount) {
		if (amount==0) return 0;
		int len = coins.length;
		int[] dp = new int[amount+1];
		dp[0] = 0;
		for (int i=1; i<amount+1; ++i) dp[i] = Integer.MAX_VALUE/2;
		for (int money=1; money<=amount; ++money) {
			for (int coinId=0; coinId<len; ++coinId) {
				if (money>=coins[coinId]) {
					dp[money] = Math.min(dp[money], dp[money-coins[coinId]]+1);
				}
			}
		}
		if (dp[amount] == Integer.MAX_VALUE/2) return -1;
		return dp[amount];
    }
}
```