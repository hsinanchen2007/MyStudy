### 解题思路
最简单的思路，不断地除以2,注意要用/，不能用//,判断结果是否为1，为1，则为True

### 代码

```python3
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n == 0:
            return False
        if n == 1:
            return True
        while n > 1:
            n = n / 2
        if n == 1:
            return True
        else:
            return False
```