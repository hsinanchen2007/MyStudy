```
class Solution:
    def simplifyPath(self, path: str) -> str:
        l = [ele for ele in path.split('/') if not (ele == '' or ele == '.')]
        res = []
        for ele in l:
            if not ele == '..':
                res.append(ele)
            else:
                if res:
                    res.pop()
        return '/'+"/".join(res)
```
