分别截取左边与右边的字符串构成子字符串，然后拼接。
```
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        a = s[0:n]
        b = s[n:]
        return b+a
```
