```
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        s = ""
        t = ""
        #将输入S翻译成s
        for i in S:
            if i == "#":
                if s:
                    s = s[:-1]
            else:
                s = s + i
        #将输入T翻译成t
        for j in T:
            if j == "#":
                if t:
                    t = t[:-1]
            else:
                t = t + j
        return s==t
```
