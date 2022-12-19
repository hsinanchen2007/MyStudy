# 简单理解：就是让后面的价格最大值减掉前面价格的最小值，即为获得的最大利润。

- 首先用min_p,max_p 分别存储最小，最大值，min_p初始化为一个无穷大的值，max_p初始化为0
- 遍历数组：分别更新min_p,max_p：如果prices[i]比上一个min_p更小，则更新为prices[i]；如果prices[i]-min_p比上一个max_p更大，则更新。
返回max_p即可。



```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_p,max_p=float('inf'),0
        for i in range(len(prices)):
            min_p=min(min_p,prices[i])
            max_p=max(max_p,prices[i]-min_p)
        return max_p
```
