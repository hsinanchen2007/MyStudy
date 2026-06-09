class Solution(object):
    def maxProfit(self, prices):
        print prices
        max_benefit = 0
        if len(prices)<2:
            return max_benefit
        min_before_today = prices[0]
        for i in range(1,len(prices)):
            if prices[i]- min_before_today > max_benefit:
                max_benefit = prices[i]- min_before_today
            if prices[i] < min_before_today:
                min_before_today = prices[i]
        return max_benefit