### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        rev = 0
        while x != 0:
            pop = int(x%10) if x>0 else -int(abs(x)%10)
            x = int(x/10)
            rev = rev*10 + pop
            if rev >= (2**31-1) or rev <=(-2**31):
                return 0
        return rev
```