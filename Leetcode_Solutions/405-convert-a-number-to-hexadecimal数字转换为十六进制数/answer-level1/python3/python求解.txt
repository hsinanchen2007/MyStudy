思路一：库函数（作弊过）

```python
class Solution:
    def toHex(self, num: int) -> str:
       return hex(num&0xFFFFFFFF)[2:]
```

思路二：位运算

```python
class Solution:
    def toHex(self, num: int) -> str:
        num &= 0xFFFFFFFF
        s = "0123456789abcdef"
        res = ""
        mask = 0b1111
        while num > 0:
            res += s[num & mask]
            num >>= 4
        return res[::-1] if res else "0"
```





