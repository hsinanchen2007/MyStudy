### 解题思路
时间复杂度：O（log（n））
空间复杂度：O（1）

### 代码

```python3
class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x
        left = 2
        right = x // 2
        num = 0
        while left <= right:
            num = (left + right) // 2
            if num **2 < x:
                left = num + 1
            elif num ** 2 > x:
                right = num - 1
            else:
                return num
        return right

```