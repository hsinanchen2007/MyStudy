### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        s_len, t_len = len(s), len(t)
        i, j = 0, 0
        while i < s_len and j < t_len:
            if s[i] == t[j]:
                i += 1
            j += 1
        return i == s_len
        
```