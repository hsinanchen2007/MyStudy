```
'''
        cost, profit = float("+inf"),0
        for price in prices:
            cost = min(price,cost)
            profit = max(price-cost,profit)
        return profit
        '''
        if len(prices)<=0: return 0
        diff = [0 for _ in range(len(prices)-1)]
        for i in range(len(prices)-1):
            diff[i] = prices[i+1]-prices[i]
        temp = max_profit = 0
        for i in range(len(prices)-1):
            temp = max(0,diff[i]+temp)
            max_profit = max(max_profit,temp)
        return max_profit
```
