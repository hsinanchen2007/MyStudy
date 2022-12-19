#贪心算法， 局部均获得最优解  最后总体就是最优解
#连续上涨，最优为 每天买卖 ，赚到每天的利润，
#连续下跌，最优为 啥也不干，不买就不亏

n=[7,1,5,3,6,4]
class Solution:
    def maxProfit(self,prices) :
        if (len(prices)<=1):
            return 0
        #min_p = prices[0]#最低的价格
        sum_p = 0 #最大的利润
        for i in range(1,len(prices)):
            if prices[i]>prices[i-1]:
                sum_p +=prices[i]-prices[i-1]

        return sum_p

solution = Solution()
print(solution.maxProfit(n))
