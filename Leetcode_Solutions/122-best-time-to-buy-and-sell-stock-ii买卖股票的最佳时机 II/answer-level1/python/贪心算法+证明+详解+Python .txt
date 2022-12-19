```
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # 很自然的会想到，希望在上坡的时候买入，到达山顶的时候卖出，在下坡的时候不买，等到了坡底买入，一旦上升就再卖出。
        # greedy property 体现在:每步都可以立刻做决定。 如果prices[i]<prices[i+1],就在i时候立刻买入，然后i+1时候卖出，不管在i+2时候和之后，价格会不会更高。因为如果i+2时候>i+1,你会在i+1再次买入然后卖出。
        # 这时候 greedy optimal 体现在这个等式:
        #  -prices[i]+prices[i+2] = (-prices[i]+prices[i+1])+(-prices[i+1]+prices[i+2])
        if len(prices)==0 or len(prices)==1: 
            return 0
        last_price = None
        balance=0
        for i in range(0,len(prices)-1):
            if last_price is not None and prices[i] > last_price:
                #比之前好，卖出股票
                balance += prices[i]
                last_price = None
            if prices[i+1]>prices[i]:
                #下一个是上坡，现在买入
                balance -= prices[i]
                last_price = prices[i]
        #记得最后1天的股票还没清算
        if last_price is not None and prices[-1] > last_price:
            balance += prices[-1]

        return balance
```
