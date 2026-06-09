遍历数组，先固定一个值，在寻找比它大的值，记录他们的差值，最后返回记录值。（用数组存储结果空间消耗大一点）
    
    class Solution:
        def maxProfit(self, prices: List[int]) -> int:
            if not prices :return 0
            #ans = [0]*len(prices)
            ans = 0
            buy_in = prices[0]
         for i in range(1,len(prices)):
                if buy_in < prices[i]:
                    #ans.append(prices[i]-buy_in)
                    ans +=prices[i]-buy_in
                    #buy_in = prices[i]
                buy_in = prices[i]
                #print(buy_in)
                #ans = max(ans,prices[i]-buy_in)
                #ans.append(prices[i]-buy_in) 
            return ans if prices!=prices.reverse() else 0
            #return max(ans) if prices!=prices.reverse() else 0