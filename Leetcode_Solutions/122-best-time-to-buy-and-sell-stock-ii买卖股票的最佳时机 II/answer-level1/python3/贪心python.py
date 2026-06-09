`    def maxProfit_1(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        tmp_profit = 0
        length = len(prices)
        for i in range(length-1):
            day_profit = prices[i+1] - prices[i]
            if day_profit > 0:
                # 今天买进，明天卖出
                tmp_profit += day_profit
        return tmp_profit`