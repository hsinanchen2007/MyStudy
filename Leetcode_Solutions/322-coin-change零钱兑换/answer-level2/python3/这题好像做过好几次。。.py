#没啥好说的，符合最优子结构
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        #dp
        #am[i]=min(am[i-1],am[i-2],am[i-5])+1
        dp = [0]
        for i in range(1,amount+1):
            min_x=1*1000000
            for j in range(len(coins)):
                if(coins[j] <= i and dp[i-coins[j]] != -1 and dp[i-coins[j]] < min_x):
                    min_x=dp[i-coins[j]]
            if(min_x==1*1000000):
                dp.append(-1)
            else:
                dp.append(min_x+1)
        return dp[amount]