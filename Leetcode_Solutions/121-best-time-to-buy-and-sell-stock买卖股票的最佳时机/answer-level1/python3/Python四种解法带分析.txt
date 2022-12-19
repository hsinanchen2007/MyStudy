### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        '''
        方法四：动态规划用来解决最优问题，使用动态规划需要满足以下条件：
            1.通过一系列的操作，寻找问题的最优解。
            2.后面的状态由前一个状态推导出来，前一个状态是最优解。
            3.每一个阶段采取的决策所决定的状态之前不会互相影响，一旦决定，就不会改变，新状态不关心之前的状态是怎么产生的，只关注状态的值。
            4.不同的决策序列会在同一个状态下产生相同的结果（回溯算法未剪枝前）。
        回到该题中，希望寻求到的是在给定的价格中，找到相差最大的两个价格，可以将该问题转化为：针对每一个价格，获取从第一个价格到目前价格的最大值。来分析以下是否符合上述的4个条件：
            1.试图寻找相差最大的两个值。
            2.对于每一个新价格所获取的利润是当前价格-最小价格和当前利润的较大者。
            3.之前状态下的最大利润确定后，后面状态只关注这个最大利润的值。
            4.在这未体现出。
        '''
        # initialize the dp[] to store the former maximum profit
        dp = [0] * len(prices)

        # initialize the minmum price
        minprice = prices[0]

        # start the dp
        for i,price in enumerate(prices):
            if i == 0:
                pass
            else:
                minprice = min(minprice, price)
                dp[i] = max(dp[i-1], price - minprice)
        
        return dp[-1]

        '''
        # 48 ms	14.5 MB
        方法三：单调栈，单调栈中的元素，可以得知最近的一个比它大或小的元素是谁。
        
        profit = 0
        stack = []
        # guard
        prices.append(-1)  
        for price in prices:
            while stack and price < stack[-1]:                
                profit = max(profit, stack[-1] - stack[0])
                temp = stack.pop()
            
            stack.append(price)
        
        return profit
        '''
                




        '''
        方法二：法一改进版，只遍历一次数组，在遍历时候记录当前天数之前的最小值和当前天数时的最大利润。
        
        minprice = int(1e9)
        maxprofit = 0
        for price in prices:
            maxprofit = max(maxprofit, price - minprice)
            minprice = min(minprice, price)
        return maxprofit

        '''

        

        '''
        方法一：暴力法，从后向前算出任意两天内的差值，记录最小差值
        # 超时，时间复杂度O（n**2）
        lenth = len(prices)
        start = -1
        profit = 0
        

        while start < lenth-1:
            start += 1
            for end in range(lenth-1, start, -1):
                if prices[end] > prices[start]:
                    diff = prices[end] - prices[start]
                    if diff > profit:
                        profit = diff
        
        return profit
    '''

```