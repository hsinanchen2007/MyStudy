### 解题思路
挺简单的，循环往后匹配就玩了

### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        m, n = len(haystack), len(needle)
        if n == 0:
            return 0
        if m == n:
            return 0 if haystack==needle else -1
        for i in range(m-n+1):
            # print(i)
            if haystack[i:i+n] == needle:
                return i
        return -1


```
44 ms 13.9 MB