class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n=len(cost)
        #创建一个dp动态面板来记录到达该层所付出的代价
        dp=[0]*(n+1)
        #可以选择直接出生在第0层或者第1层
        dp[0]=0
        dp[1]=0
        for i in range(2,n+1):
            #要移动到第i层只能通过i-1层或i-2层
            #以移动两层为例，从i-2移动到i需要把到达该层所需的代价dp[i-2]加上通过该层的过路费cost[i-2]
            #i-1层同理
            #到达i层的最小花费应该是前两种方法中的较小者
            dp[i]=min(dp[i-2]+cost[i-2],dp[i-1]+cost[i-1])
        return dp[n]