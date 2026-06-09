```
class Solution:
    def simplifyPath(self, path: str) -> str:
        parts = path.split('/')
        res = []
        for x in parts:
            if x == '..':
                if res:
                    res.pop()
            elif x in {'.',''}:
                pass
            else:
                res.append(x)
        return '/'+'/'.join(res)
```
