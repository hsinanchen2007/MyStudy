### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        i = 0
        while i < len(s):
            if s[i].isalpha() or s[i].isdigit():
                i += 1
                continue
            else:
                s = s[:i]+s[i+1:]
        return s[:] == s[::-1]
```