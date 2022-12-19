这是一道动态规划的题，如果用暴力法会超出界限，思路和题53题的最大子序和相似
从列表头部开始遍历，保存z最小的值到minp，最大值maxp初始为0
如果prices[i]-minp小于最大值，最大值不变
否则更新最大值


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices)==0:
            return 0
        maxp=0
        minp = prices[0]
        for i in range(1,len(prices)):
            if prices[i]<minp:
                minp = prices[i]
            elif prices[i]-minp>maxp:
                maxp=prices[i]-minp
                
        return maxp
                