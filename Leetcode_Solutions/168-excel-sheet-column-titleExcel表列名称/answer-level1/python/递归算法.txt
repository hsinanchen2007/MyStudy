### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def convertToTitle(self, n: int) -> str:
        n = n-1
        if n<26:  
            return '' + chr(n+65)
        return self.convertToTitle(n // 26) + chr(n%26+65)
```