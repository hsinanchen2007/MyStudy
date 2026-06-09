### 解题思路
从haystack第一个字符开始，往后取与needle等长度的字符串来比较

### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle=="":
            return 0
        length=len(needle)
        for i in range(len(haystack)-length+1):
            if haystack[i:i+length]==needle:
                return i
        return -1
```