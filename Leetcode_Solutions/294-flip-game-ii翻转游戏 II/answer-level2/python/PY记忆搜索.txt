```
class Solution:
    def canWin(self, s: str) -> bool:
        win,lose=set(),set()
        def h(s):
            if s in win:
                return True
            if s in lose:
                return False
            if '++' not in s:
                lose.add(s)
                return False
            for i in range(len(s)-1):
                if s[i]==s[i+1]=='+':
                    t=s[:i]+'--'+s[i+2:]
                    if not h(t):
                        win.add(s)
                        return True
            return False
        
        return h(s)
```
