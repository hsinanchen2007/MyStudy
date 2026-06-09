class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        sum = 0
        for i in range(len(prices)-1):
            temp = prices[i+1] - prices[i]
            if temp > 0:
                # print(temp)
                sum += temp
        return sum