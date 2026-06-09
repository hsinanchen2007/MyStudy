### 解题思路
这个题一开始，我是直接想用两个for循环的，但是直接超过限制了。
所以就需要减轻代码的负担

于是我想出来了代码1.0：就是把今天股价跟之前最小的股价之差，差最大即可
我是习惯把思路直接翻译成代码（不太习惯再经过思考简化代码。
于是就有了用时：4692ms~~~
#1.0
        # if prices == [] or len(prices) == 1:
        #     return 0
        # money = 0
        # ans = []
        # for i in range(len(prices)):
        #     if ans == []:
        #         ans.append(prices[i])
        #         continue
        #     if prices[i] -  min(ans) > money:
        #         money = prices[i] - min(ans)
        #     ans.append(prices[i])
        #
        # return money

然后看来别人的代码，做了稍许优化，把之前的列表优化成一个变量，这样果然只跑了28ms
希望看了会对你有所帮助或者图一乐

#2.0
class Solution:
    def maxProfit(self, prices) -> int:
        n = len(prices)
        if n == 0 or n == 1:
            return 0
        money = 0
        min_lis = prices[0]
        for i in range(1,n):
            if prices[i] - min_lis > money:
                money = prices[i] - min_lis
            if prices[i] < min_lis:
                min_lis = prices[i]
            

        return money
```