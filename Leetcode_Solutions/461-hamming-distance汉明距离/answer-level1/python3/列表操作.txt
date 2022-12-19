>执行用时 :28 ms, 在所有 python3 提交中击败了98.93%的用户
内存消耗 :12.7 MB, 在所有 python3 提交中击败了99.45%的用户
-------

```python
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        num = 0
        res = []
        while x != 0 or y != 0:
            res.append((x%2, y%2))
            x //= 2
            y //= 2
        for xii, yii in res:
            if xii != yii:
                num += 1 
        return num
```
