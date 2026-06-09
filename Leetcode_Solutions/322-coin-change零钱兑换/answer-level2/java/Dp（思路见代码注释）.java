### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int coinChange(int[] coins, int amount) {
		int dp[] = new int[amount+1] ;
		
        for(int i=1;i<dp.length;i++) dp[i] = Integer.MAX_VALUE-1 ; //最大值选择有技巧，可能没法凑，求和溢出了，返回个负数，题目答案错误也有可能。
		//dp[0] = 0 ;

		Arrays.sort(coins) ;
		
		for(int i=1;i<=amount;i++) {
			
			for(int temp:coins) {
				if(i-temp<0) continue ; // 这枚硬币不能用来凑这个i，继续找下一个
				dp[i] = Math.min(dp[i],dp[i-temp]+1) ; //这枚硬币能用来凑这个i，我们看下没用这枚硬币和用了这枚硬币哪个用的硬币更少
			}
			
		}
		
		if(dp[amount]==Integer.MAX_VALUE-1)
			return -1 ;
		return dp[amount] ;
    }
}
```