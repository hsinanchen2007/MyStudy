### 解题思路
利用python独有的字符串切片
简洁明了

### 代码

```python3
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        return s[n:] + s[:n]
```