### 解题思路
二分法

### 代码

```python3
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        start, last = 0, num
        while start < last:
            mid = (start + last) // 2
            if mid ** 2 < num:
                start = mid + 1
            else:
                last = mid
        return start**2 == num
            


        
```