```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit_left = []
        profit_right = []
        profit = []
        out =[]
        left = 0
        right = 0
        for i in range(1, len(prices)):
            if prices[i] < prices[i - 1] :
                if right > left:
                    profit_left.append(left)
                    profit_right.append(right)
                left = i
            else:
                right = i
        if right ==  len(prices) - 1:
            profit_left.append(left)
            profit_right.append(right)
        for i in range(len(profit_left)):
            for j in range(i,len(profit_right)):
                profit.append([prices[profit_right[j]] - prices[profit_left[i]]] + [profit_left[i]] + [profit_right[j]])
        profit = sorted(profit,key = lambda x:x[0])
        if len(profit) >= 2:
            for i in range(len(profit)-1,-1,-1):
                for j in range(i-1,-1,-1):
                    if profit[j][2] < profit[i][1] or profit[i][2] < profit[j][1] :
                        out.append(profit[j][0] + profit[i][0])
                        break
                    else:
                        continue
            return(max(out))
        elif len(profit) == 1:
            return(profit[0][0])
        else:
            return 0
```

自己写的方法，有点慢。。。大概要200ms才能成功，主要思想是每个上升沿的左端和右端都记录下来，然后判断两个被选取的上升沿的左端是否比另一个的右端要大。贴完自己的，赶紧去看看其他大佬的方法。唉想当码农不容易啊。。。
