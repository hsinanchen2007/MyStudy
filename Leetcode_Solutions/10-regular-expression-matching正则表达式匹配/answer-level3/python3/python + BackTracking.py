```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # '.' matches any single character.
        # '*' matches zero or more of the preceding element.
        # s -> match -> p
        # backtracking method
        # 'a aa'
        # 'a* aaa'
        if s == p: return True
        if p == '': return False

        if len(p) >= 2 and p[1] == '*':
            if s!= '' and (s[0] == p[0] or p[0] == '.'):
                return self.isMatch(s[1:], p) or self.isMatch(s, p[2:])
            else:
                return self.isMatch(s, p[2:])
        else:
            if s != '' and (s[0] == p[0] or p[0] == '.'):
                return self.isMatch(s[1:], p[1:])
            else: return False
```