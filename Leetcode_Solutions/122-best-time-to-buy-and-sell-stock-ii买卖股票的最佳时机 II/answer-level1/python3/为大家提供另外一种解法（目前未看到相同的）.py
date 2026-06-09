![1575465769(1).jpg](https://pic.leetcode-cn.com/5018c912e940ff55d36c7d0a50260174b2ace9f30e719e3225e8a4368abd2e2d-1575465769\(1\).jpg)

先看代码:
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) <= 1 : return 0
        min_p = prices[0]
        cur_p = 0
        max_p = []
        for i in range(len(prices)):
            min_p = min(min_p,prices[i])
            cur_p = max(cur_p,prices[i]-min_p)
            if cur_p > 0:
                max_p.append(cur_p)
                min_p = prices[i]
                cur_p = 0
        return sum(max_p)
```
逻辑思路：1.需要三个指针，最小价格，当前利润，利润总和。
2.计算今天价格减去前一天的价格，计算利润，保留在cur_p中，如果不获利(cur_p<=0)，min_p不更新。3.获利后(cur_p>0),记录利润，放在max_p中，重点来了，**此时一定要把min_p跟新为当前的prices[i]**， 大家多揣摩一下这句话，就会明白。4.然后循环2，3即可，直到计算出所有的利润，求和即可。