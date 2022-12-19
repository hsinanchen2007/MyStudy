### 解题思路
种类数与妹妹能拿的糖果数取小值

### 代码

```python
class Solution(object):
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        return min(len(collections.Counter(candies)), len(candies) / 2)

```