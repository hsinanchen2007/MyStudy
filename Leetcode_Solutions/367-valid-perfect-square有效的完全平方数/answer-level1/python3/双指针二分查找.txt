### 解题思路
双指针二分查找

### 代码

```python3
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        l = 0
        r = num
        while l <= r:
            m = (l+r)//2
            if m**2 == num:
                return True
            elif m**2 > num:
                r = m - 1
            else:
                l = m + 1
        return False
```