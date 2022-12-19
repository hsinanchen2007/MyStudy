先做并查集，再检验符号。

```python
class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        p = {chr(97+i):{chr(97+i)} for i in range(26)}      #并查集初始化
        for a, s, _, b in equations:
            if s == '=' and p[a] != p[b]:       #如果是等号，就取并集
                p[a] |= p[b]
                for c in p[b]:
                    p[c] = p[a]
        for a, s, _, b in equations:        #符号检查
            if (s == '=') == (p[a] != p[b]):
                return False
        return True
```
