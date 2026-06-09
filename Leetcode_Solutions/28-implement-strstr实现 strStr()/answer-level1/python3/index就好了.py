### 解题思路
index 返回位置

### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        try:
            return haystack.index(needle)
        except:
            return -1
```