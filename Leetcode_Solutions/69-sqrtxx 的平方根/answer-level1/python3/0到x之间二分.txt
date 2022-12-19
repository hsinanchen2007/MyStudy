### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def mySqrt(self, x: int) -> int:
            # 取0到这个数
            left = 0
            right = x
            while left < right:
                mid = (left + right + 1) >> 1
                square = mid * mid
                if square > x:
                    right = mid - 1
                else:
                    left = mid
            return left
```