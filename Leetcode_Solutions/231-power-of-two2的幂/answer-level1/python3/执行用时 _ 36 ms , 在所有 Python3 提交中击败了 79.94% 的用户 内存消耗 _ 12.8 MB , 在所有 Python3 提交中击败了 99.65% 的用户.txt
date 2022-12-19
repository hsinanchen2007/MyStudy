### 解题思路
常规思路，虽然赶不上大神的位运算，但是也凑合

### 代码

```python3
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n == 1:
            return True
        while n > 0:
            if n%2 ==1:
                return False
            else:
                if n//2 == 1:
                    return True
                n //=2
```