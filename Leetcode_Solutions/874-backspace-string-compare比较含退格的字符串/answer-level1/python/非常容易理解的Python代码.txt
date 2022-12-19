```
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        s = []
        for i in S:
            if i == '#':
                if s:
                    s.pop()
            else:
                s.append(i)

        t = []
        for j in T:
            if j == '#':
                if t:
                    t.pop()
            else:
                t.append(j)
        return s == t


```
