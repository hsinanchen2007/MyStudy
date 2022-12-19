class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        sum = 0
        low_price = -1
        for i in range(len(prices)-1):
            if (low_price == -1):
                if (prices[i] < prices[i+1]):
                    low_price = prices[i]
            else:
                if (prices[i] > prices[i+1]):
                    sum += prices[i] - low_price
                    low_price = -1
        # the last day, sell out 
        if low_price != -1:
            sum += prices[-1] - low_price
        return sum