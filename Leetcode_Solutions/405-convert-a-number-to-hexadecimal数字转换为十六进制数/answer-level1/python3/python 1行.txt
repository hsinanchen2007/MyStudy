```
class Solution:
    def toHex(self, num: int) -> str:
        return ''.join('0123456789abcdef'[num >> i*4 & 0xF] for i in range(7,-1,-1)).lstrip('0') or '0'
```
