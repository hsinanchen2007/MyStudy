### 解题思路
将26进制转换成十进制数；

### 代码

```python3
class Solution:
    """
    类似于将26进制转换成十进制；
    """
    def titleToNumber(self, s: str) -> int:
        if len(s) == 0:
            return 0
        
        # res = (ord(s[0]) - ord('A') + 1)
        res = 0
        for i in range(len(s)):
            res = res*26 + (ord(s[i]) - ord('A') + 1)
        return res
```