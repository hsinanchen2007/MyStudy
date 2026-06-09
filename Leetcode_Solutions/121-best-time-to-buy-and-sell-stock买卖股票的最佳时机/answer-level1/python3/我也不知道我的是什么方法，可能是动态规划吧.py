class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) <= 1:
            return 0

        i = 0
        max_num = float('-inf')
        min_num = float('inf')
        profit = 0

        for i in range(len(prices) - 1):
            if prices[i] < prices[i + 1]:
                max_num = prices[i + 1]
                min_num = prices[i]
                profit = max_num - min_num
                break

        if i == len(prices) - 1:
            return 0

        if max_num == float('-inf') and min_num == float('inf'):
            return 0

        for j in range(i + 2, len(prices)):
            if prices[j] > max_num:
                max_num = prices[j]
                if max_num - min_num > profit:
                    profit = max_num - min_num
            elif prices[j] < min_num:
                min_num = prices[j]
                max_num = prices[j]
        return profit


            