### 解题思路
KMP在pattern较长和pattern里重复较多的时候才有优势。

### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == '':
            return 0
        pre_table = [-1]
        i, j, n = 0, -1, len(needle)
        while i < n - 1:
            while j >= 0 and needle[i] != needle[j]:
                j = pre_table[j]
            i += 1
            j += 1
            pre_table.append(j)
        j = 0
        for i in range(len(haystack)):
            while j != -1 and haystack[i] != needle[j]:
                j = pre_table[j]
            if j == -1:
                j = 0
            else:
                j += 1
            if j == n:
                return i - n + 1
        return -1
```