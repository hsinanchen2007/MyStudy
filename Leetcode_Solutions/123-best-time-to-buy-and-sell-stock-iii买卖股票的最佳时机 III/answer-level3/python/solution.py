### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    # def oneProfit(self,prices):
    #     table = [0] * len(prices) 
    #     cur_min = prices[0]
    #     profit = 0
    #     for i in range(1,len(prices)):
    #         cur_min = min(cur_min,prices[i])
    #         table[i] = max(table[i-1],prices[i] - cur_min)
    #         profit = max(profit,prices[i] - cur_min)
    #     return table,profit
    
    # def secondProfit(self,prices):
    #     one_table,one_profit = self.oneProfit(prices)
    #     sec_table = [0] * len(prices) 
    #     for i in range(1,len(prices)):
    #         for j in range(1,i):
    #             if(prices[j] < prices[i]):
    #                 sec_table[i] = max(sec_table[i],one_table[j-1] + prices[i] - prices[j])
    #         sec_table[i] = max(sec_table[i],sec_table[i-1])
    #     return max(one_profit,sec_table[len(prices)-1])
    #     # return sec_table[len(prices)-1]



    # def oneProfit(self,prices,left,right):
    #     if left >= right:
    #         return 0
    #     cur_min = prices[left]
    #     profit = 0
    #     diff = right - left
    #     for i in range(1,diff+1):
    #         cur_min = min(cur_min,prices[left+i])
    #         profit = max(profit,prices[left+i] - cur_min)
    #     return profit

    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) == 0:
            return 0

        dp = [[0] * 6 for _ in range(len(prices)+1)]
        dp[0][1] = 0
        dp[0][2] = dp[0][3] = dp[0][4] = dp[0][5] = -100

        for i in range(1,len(prices)+1):
            for j in range(1,6):
                if j == 1 or j == 3 or j == 5:
                    dp[i][j] = dp[i-1][j]
                    if j > 1 and i >= 2:
                        dp[i][j] = max(dp[i][j],dp[i-1][j-1] + (prices[i-1] - prices[i-2]))
                elif j == 2 or j == 4:
                    dp[i][j] = dp[i-1][j-1]
                    if i >= 2:
                        dp[i][j] = max(dp[i][j],dp[i-1][j] + (prices[i-1] - prices[i-2]))
        return max(dp[len(prices)][1], max(dp[len(prices)][3],dp[len(prices)][5]))




        # return self.secondProfit(prices)
        # if len(prices) == 0:
        #     return 0
        # pro = 0
        # for i in range(len(prices)):
        #     new_pro = self.oneProfit(prices,0,i) + self.oneProfit(prices,i+1,len(prices)-1)
        #     pro = max(pro,new_pro)
        # return pro


```