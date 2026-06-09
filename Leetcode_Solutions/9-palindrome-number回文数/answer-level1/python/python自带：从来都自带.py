### 解题思路
简单，此处就不说了。
### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        a=str(x)
        b=list(a[:])
        c=list(a[:])
        c.reverse()
        return b==c
```