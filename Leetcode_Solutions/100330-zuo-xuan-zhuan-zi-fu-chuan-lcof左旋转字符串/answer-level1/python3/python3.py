### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        n= n%len(s)
        return s[n:]+s[:n]
```