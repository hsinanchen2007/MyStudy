没有使用任何的优化 单纯的背包问题
dp[i][j]是总数为j时刻,在0-i范围内任意取值,
dp[i][j]=min(dp[i-1][j],dp[i][j-k*coins[i]]+k)
意思是从0-I-1范围内取得刚好为j总数的张数和从0-if范围内取得刚好总数为j-k*coins[i]的答案+k的最小值

```
class Solution {
  //这是我能想到的最普遍的解法了 这个题目实际上就是完全背包问题 他的最大难点是卡住==这个关键  而完全背包问题是<=即	
	int coinChange(int[] coins, int amount) {	
		if(coins==null||coins.length<1)
			return -1;
		int dp[][]=new int[coins.length][amount+1];
		//dp[i][j]是总数为j时刻,在0-i范围内任意取值,dp[i][j]=min(dp[i-1][j],dp[i][j-k*coins[i]]+k);
		for(int sum=0;sum<=amount;sum++) {
			dp[0][sum]=(sum%coins[0]==0)?sum/coins[0]:10000;
		}
		for(int index=1;index<coins.length;index++) {
			for(int sum=0;sum<=amount;sum++) {
				dp[index][sum]=dp[index-1][sum];
				int pieces=1;
				while(sum-pieces*coins[index]>=0) {
					dp[index][sum]=Math.min(dp[index][sum], dp[index][sum-pieces*coins[index]]+pieces);
					pieces++;
				}
			}
		}
		return dp[coins.length-1][amount]>=10000?-1:dp[coins.length-1][amount];
	}
}
```