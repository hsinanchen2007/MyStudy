### 解题思路
用python中str()之后反转很方便

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        if x<0:
            rev = -int(str(-x)[::-1])
        else:
            rev = int(str(x)[::-1])
        if rev>=2**31-1 or rev<=-2**31:
            return 0
        else:
            return rev

```