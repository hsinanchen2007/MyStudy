
1. p都是字母，判断是否相等
否则判断首字符：
2. `?`则匹配了一个字符，继续判断后面`s[1:]`和`p[1:]`判断
3. `*`两种情况：1）匹配空字符，`s`和`p[1:]`判断. 2）匹配1个或多个字符，则`s`的首字符被匹配，继续`s[1:]`和`p`的判断
4. 都是字母。1）相同，继续后面`s[1:]`和`p[1:]`判断. 2）不同，返回False
```python
functools import lru_cache
class Solution:
    @lru_cache(1800)
    def isMatch(self, s: str, p: str) -> bool:
        lenS = len(s)
        lenP = len(p)
        if '?' not in p and '*' not in p:
            return lenS == lenP and s == p
        if lenS == 0:
            return self.isMatch(s,p[1:]) if p[0] == '*' else False
        if p[0] == '?':
            return self.isMatch(s[1:],p[1:])
        if p[0] == '*':
            return self.isMatch(s,p[1:]) or self.isMatch(s[1:],p)
        return self.isMatch(s[1:],p[1:]) if s[0] == p[0] else False
```