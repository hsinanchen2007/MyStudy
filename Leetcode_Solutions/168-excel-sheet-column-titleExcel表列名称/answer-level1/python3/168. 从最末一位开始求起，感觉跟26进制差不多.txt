### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def convertToTitle(self, n: int) -> str:
        s = ''
        while n:
            n -= 1
            s = chr(n%26+65) + s
            n //= 26
        
        return s
```