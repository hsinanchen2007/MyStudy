### 解题思路
直接拿字符串利用python的分割进行切割然后与目标值进行比较就好啦！

### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        a = len(needle)
        b = len(haystack)
        for i in range(b - a + 1):
            if haystack[i:i+a] == needle:
                return i
        return -1

```