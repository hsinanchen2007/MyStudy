### 解题思路

平均值如果保持不变，由于取整的原因，很容易陷入死循环。
当猜的值偏小时，平均值要向大的方向偏移一个单位
当猜的值偏大时，平均值要向小的方向偏移一个单位
如果搞反了，很容易在mid处陷入无限循环
### 代码

```python3
# The guess API is already defined for you.
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        ret = self.binary(0, n)
        return ret

    def binary(self,left,right):
        mid = (left + right)//2
        g = guess(mid)
        if g == 1:
            return self.binary(mid+1,right)
        if g == -1:
            return self.binary(left, mid-1)
        if g == 0:
            return mid
```