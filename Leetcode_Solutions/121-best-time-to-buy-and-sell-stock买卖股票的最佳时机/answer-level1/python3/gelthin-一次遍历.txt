### 解题思路
很简单，只需要在遍历过程中保存当前遇到的最小元素的值即可。
然后若 x >= current_min, 则计算 x-current_min, 并更新 result = max(result, x-current_min)
若 x < current_min, 则更新 current_min = x

这个思路是自己随机想出来的，看了下评论区的讨论，如果从动态规划的角度来考虑，会非常直观地就能够想出此思路。
这就是学没学过算法的巨大差别！
DP: 前 i 天的最大收益 = max{ 前 i-1 天的最大收益, 第 i 天的价格-前 i-1 天的价格最小值}



### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        if (n == 0)or (n==1):
            return 0
        if n==2:
            if prices[0]>=prices[1]:
                return 0
            else:
                return prices[1]-prices[0]
        result = 0
        current_min = prices[0]
        for x in prices[1:]:
            if x < current_min:
                current_min = x
            else:
                tmp = x-current_min
                if tmp > result:
                    result = tmp
        return result
        
```