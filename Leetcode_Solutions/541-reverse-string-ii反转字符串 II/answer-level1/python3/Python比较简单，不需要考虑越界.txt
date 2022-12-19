```
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        return ''.join((s[x:x + k][::-1] + s[x + k:x + 2 * k] for x in range(0, len(s), 2 * k)))
```
可读性高一点：

```
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        i = 2 * k
        e = range(0, len(s), i)
        ss = (s[x:x + k][::-1] + s[x + k:x + i] for x in e)
        return ''.join(ss)
```