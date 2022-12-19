### 解题思路
貌似就三种情况，直接写就完了

### 代码

```python
class Solution(object):
    def numMovesStones(self, x, y, z):
        """
        :type a: int
        :type b: int
        :type c: int
        :rtype: List[int]
        """
        a = min(x, y, z)
        c = max(x, y, z)
        b = x + y + z - a - c

        if b - a == 1 and c - b == 1:
            return [0, 0]
        if b - a <= 2 or c - b <= 2:
            return [1, c - a - 2]
        else:
            return [2, c - a - 2]
```