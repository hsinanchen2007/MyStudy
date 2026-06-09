
# def maxProfit(prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if(not prices):return 0
        last = prices[0]
        sellThis = 0
        res = 0
        for i in prices[1:]:
            if(i>=last):
                sellThis += i-last
            else:
                sellThis = max(0,(i - last + sellThis))
            last = i
            res = max(res,sellThis)
        return res


每次计算卖出当前股票的最高收益，
当前股票最高收益等于前一天股票最高收益 加上 当前股票与前一天股票的差价（如果负增长后小于零记为0）