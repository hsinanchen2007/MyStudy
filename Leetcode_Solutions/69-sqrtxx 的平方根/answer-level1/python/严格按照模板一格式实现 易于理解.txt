```
class Solution:
    def mySqrt(self, x: int) -> int:
        left, right = 0, x

        while left <= right:
            mid = left + (right - left) // 2

            if mid * mid == x:
                return mid
            elif mid * mid < x:
                left = mid + 1
            else:
                # 如果 mid 为第一个平方大于 x 的整数, mid - 1 即为最后一个平方不大于 x 的整数
                # 所以最后返回应返回 right
                right = mid - 1

        return right
```
