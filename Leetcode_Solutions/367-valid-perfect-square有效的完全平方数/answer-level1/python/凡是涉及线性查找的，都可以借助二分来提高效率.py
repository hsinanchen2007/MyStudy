### 解题思路
凡是涉及线性查找的，都可以借助二分来提高效率

### 代码

```python
class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        left, right = 0, num
        while left <= right:
            mid = (left + right) // 2
            if mid*mid == num:
                return True
            elif mid*mid < num:
                left = mid + 1
            elif mid*mid > num:
                right = mid - 1
        return False
```