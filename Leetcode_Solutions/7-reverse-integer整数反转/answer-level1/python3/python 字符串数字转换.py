### 解题思路
简单的转换
边界条件要判断
### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        s=str(abs(x))
        res=int(s[::-1])
        if res<=2**-31 or res>=2**31-1:
            return 0
        return res if x>=0 else -res

```