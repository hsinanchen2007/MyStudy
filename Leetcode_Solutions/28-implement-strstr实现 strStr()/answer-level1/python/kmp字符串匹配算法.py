### 解题思路
时间复杂度：O（m+n）
空间复杂度：O(n)

### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not haystack and needle:
            return -1
        if not needle:
            return 0
        i = -1
        j = -1
        next_str = self.get_next_str(needle)
        while i < len(haystack) and j < len(needle):
            if j == -1 or haystack[i] == needle[j]:
                i += 1
                j += 1
            else:
                j = next_str[j]
        if j >= len(needle) and i <= len(haystack):
            return i - len(needle)
        elif i == len(haystack) and j == len(needle) - 1 and haystack[i-1] == needle[j]:
            return i - len(needle)
        else:
            return -1

    def get_next_str(self, temp_str):
        i = 1
        j = 0
        next_str = [-1 for i in range(len(temp_str))]
        if len(next_str) > 1:
            next_str[1] = 0
        while i < len(temp_str) - 1:
            if j == -1 or temp_str[i] == temp_str[j]:
                i += 1
                j += 1
                next_str[i] = j
            else:
                j = next_str[j]
        return next_str
```