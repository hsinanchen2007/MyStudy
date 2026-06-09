### 解题思路
感觉这道题就是这个解法了，暂时没想到别的解法

一次遍历，找到最小差，属于动态规划类型

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices)==0:
            return 0
        difference=0
        minimum=prices[0]
        for i in prices:
            difference=i-minimum if difference<i-minimum else difference
            minimum=i if minimum>i else minimum
        return difference if difference>0 else 0
```