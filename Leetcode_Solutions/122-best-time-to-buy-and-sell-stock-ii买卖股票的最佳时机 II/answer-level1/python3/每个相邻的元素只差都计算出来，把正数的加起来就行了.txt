class Solution:

    def maxProfit(self, prices: List[int]) -> int:

        if len(prices)==0 or len(prices)==1:
            return 0

        l = []
        for i in range(1,len(prices)):
            money = prices[i] - prices[i-1]
            if money > 0:
                l.append(money)
                
        return sum(l)