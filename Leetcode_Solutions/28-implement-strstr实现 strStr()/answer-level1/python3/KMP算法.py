### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:

        def get_next(p_str: str):
            next = [None] * (len(p_str) + 1)
            next[0] = next[1] = 0
            for i in range(1, len(p_str)):
                j = next[i]
                while j and p_str[i] != p_str[j]:
                    j = next[j]
                next[i + 1] = j + 1 if p_str[i] == p_str[j] else 0

            return next
        if not needle:
            return 0
        next = get_next(needle)
        j = 0
        for i in range(len(haystack)):
            while j and haystack[i] != needle[j]:
                j = next[j]
            if haystack[i] == needle[j]:
                j += 1
            if j == len(needle):
                return i - len(needle) + 1

        return -1
```