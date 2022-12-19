### 解题思路
此处撰写解题思路
# 一次遍历，找到最低价格，计算差值，在所有的差值中找最大的返回

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n=len(prices)
        if n==0:
            return 0
        minv=prices[0]   #设第一天为最小值
        res=0            #差值为0
        for i in range(1,n):
            res=max(res,prices[i]-minv)#找到最大的差价
            minv=min(minv,prices[i])#看看今天会不会更低
        return res
```