### 解题思路
我觉得考点不是切片吧？
### 代码
```python
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        if not s:return s
        return s[n:]+s[:n]
```