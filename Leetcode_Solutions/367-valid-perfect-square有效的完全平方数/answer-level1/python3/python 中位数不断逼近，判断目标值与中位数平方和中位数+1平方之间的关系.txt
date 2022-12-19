### 解题思路
中位数不断逼近，判断目标值与中位数平方和中位数+1平方之间的关系

### 代码

```python3
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        if num == 0:
            return False

        l, r = 0, num
        while l <= r:
            mid = int(l + (r - l) / 2)
            if mid * mid < num and (mid + 1) * (mid + 1) > num:
                return False
            if mid * mid > num:
                r = mid - 1
            else:
                l = mid + 1
        return True
```