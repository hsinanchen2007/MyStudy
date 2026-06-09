精选的那个解题方法很有趣，我是直接遍历一遍list，设置两个变量i，j代表第一天和第二天的价格。利用异常检测来控制了一些极端的情况，超过了96.66%的python解法。

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        j = 0
        all_count = 0
        while(1):
            try:
                i = j
                j = i + 1
                if prices[i] < prices[j]:
                    try:
                        while(prices[j+1] >= prices[j]):
                            j += 1
                        all_count += prices[j] - prices[i]
                    except:
                        all_count += prices[j] - prices[i]
            except:
                return(all_count)
    