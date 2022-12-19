### 解题思路
调用一下str.strip, str.isalnum, ''.join这些API走流程而已!

### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        L = []
        for c in s.strip():
            if c.isalnum():
                L.append(c.upper())
        ss = ''.join(L)
        for i in range(len(ss) // 2):
            if ss[i] != ss[len(ss) - 1 - i]:
                return False
        return True
```