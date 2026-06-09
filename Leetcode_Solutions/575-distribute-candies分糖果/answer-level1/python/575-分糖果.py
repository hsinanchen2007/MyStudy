### 解题思路
糖果数量是偶数
统计糖果种类
如果种类超过数量的一半，都给妹妹，妹妹得到的糖种类各不相同
如果种类小于数量的一半，都给妹妹，妹妹得到所有种类的糖

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: List[int]) -> int:
        candi = set(candies)
        if len(candi) >= len(candies) // 2:
            return len(candies) // 2
        return len(candi)

```