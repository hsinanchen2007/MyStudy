```
class Solution:
    def compressString(self, S: str) -> str:
        import re
        p=re.compile(r'([a-zA-Z])(\1*)')
        S1=p.sub(lambda m:m.group(1)+str(1+len(m.group(2))),S)
        return S1 if len(S)>len(S1) else S
```
