```python
class Solution:
    def compressString(self, S: str) -> str:
        if not S:
            return ""
        result = ""
        cur = S[0]
        count = 0
        for s in S:
            if s == cur:
                count += 1
            else:
                result += "%s%d" % (cur, count)
                cur = s
                count = 1
        result += "%s%d" % (cur, count)
        return result if len(result)<len(S) else S
```
