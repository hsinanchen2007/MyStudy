### 解题思路
Python3 一行秒杀

### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        return haystack.index(needle) if needle in haystack else -1
```