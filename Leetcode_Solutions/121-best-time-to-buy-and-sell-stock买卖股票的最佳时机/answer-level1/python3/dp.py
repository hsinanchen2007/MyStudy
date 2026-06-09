class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) <= 1:
            return 0
        
        res = []
        res.append([0, -prices[0]])

        for i in range(1, len(prices)):
            res.append(
                [
                    max(res[i - 1][0], res[i - 1][1] + prices[i]),
                    max(res[i - 1][1], -prices[i])
                ]
            )
        
        return res[len(prices) - 1][0]