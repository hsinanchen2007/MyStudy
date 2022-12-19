### 解题思路
顺序遍历，res[i]表示，以当前元素为卖出可获得的最大利润，最后相当于求max(res[])
res[i]的求法：记录在在这个元素之前的最小值，用当前元素-最小值small，即为以当前元素为结尾的最大值

### 代码

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices: return 0
        res=0#记录res[i]的最大值
        small=prices[0]#记录每一步之前的最小值
        for i in range(1,len(prices)):
            res=max(res,prices[i]-small)
            if prices[i]<small:
                small=prices[i]
        return res

```