### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def mySqrt(self, x: int) -> int:
        # 数学问题if x/2>2: x*x > x+x因此我们可以取x/2作为一个限制
        if x == 0:
            return 0
        if x//2 < 2:
            return 1
        if x // 2 == 2:
            return 2
        left = 1
        right = x//2
        mid = (left + right)//2
        
        while left < (right-1):
            if mid * mid < x:
                # right to search
                left = mid
                mid = (left + right)//2
            if mid * mid == x:
                return mid
            if mid * mid > x:
                right = mid
                mid = (left + right)//2
        return left

```