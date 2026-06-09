### 解题思路
简单的题目对自己来说，都需要好一阵子琢磨，手动捂脸。。。
思路如下：
- 使用一个变量imin存储遍历过的元素中的最小值；
- 使用一个rst记录当前买入卖出的最大利润；
- 每次计算利润的时候，
- 第一，要先判断当前价格是否大于之前的最小值，若小于，则更新最小值，继续下一个遍历；
- 第二，若当前价格大于等于之前的最小值，则判断以当前价格卖出所得利润，是否大于已经存在的最大利润，两者之间取最大值即可；

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        lgth = len(prices)
        if lgth < 2:
            return 0

        rst = 0
        imin = prices[0]
        for i in range(1, lgth):
            if prices[i] < imin:
                imin = prices[i]
                continue
            tmp = prices[i] - imin
            rst = max(rst, tmp)

        return rst
```