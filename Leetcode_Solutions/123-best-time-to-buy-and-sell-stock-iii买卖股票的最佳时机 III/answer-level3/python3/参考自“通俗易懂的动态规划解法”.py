class Solution:
    #两次买卖可以都发生在同一天
    #本题是对非递归动态规划的一次练习，
    #时间复杂度为O(5N)==O(N)
    #定义5种状态：
    #0：未持股，未发生过买卖
    #1：持股，买入过一次
    #2：未持股，卖出过一次
    #3：持股，卖出过一次，买入两次
    #4：未持股，卖出过两次
    def maxProfit(self, prices):
        leng=len(prices)
        if leng==0:
            return 0
        dp=[[0]*5 for i in range(leng)]#dp[i][a]表示第i天处于状态a时可以获得的最大利润 
        dp[0][0]=0
        dp[0][1]=-prices[0]
        dp[0][2]=0
        dp[0][3]=-prices[0]
        dp[0][4]=0
        for i in range(1,leng):
            dp[i][1]=max(-prices[i],dp[i-1][1])#一种情况是今天买入，另一种是今天之前的某一天买入
            dp[i][2]=max(dp[i][1]+prices[i],dp[i-1][2])#第一次卖出发生在今天，另一种是卖出一次发生在今天之前的某一天
            dp[i][3]=max(dp[i][2]-prices[i],dp[i-1][3])#第二次买入发生在今天，另一种是发生今天之前的某一天
            dp[i][4]=max(dp[i][3]+prices[i],dp[i-1][4])#第二次卖出发生在今天，另一种是发生在今天前的某一天
        return dp[leng-1][4]