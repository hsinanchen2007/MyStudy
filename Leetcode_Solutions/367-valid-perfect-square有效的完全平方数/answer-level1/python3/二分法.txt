### 解题思路
典型二分法，套模板就行

### 代码

```python3
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        left = 0
        right = num
        while left+1 < right:
            mid = left + (right - left)//2
            tmp = mid * mid
            if tmp == num:
                return True
            elif tmp > num:
                right = mid
            else:
                # tmp < num
                left = mid
        if right * right == num:
            return right
        else:
            False
            
```