### 解题思路
逻辑解法

### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        needle_len = len(needle)
        haystack_len = len(haystack)
        if needle_len == 0:
            return 0
        if needle_len > haystack_len:
            return -1

        for i in range(haystack_len - needle_len + 1):
            if haystack[i: i+needle_len] == needle:
                return i
        return -1
```