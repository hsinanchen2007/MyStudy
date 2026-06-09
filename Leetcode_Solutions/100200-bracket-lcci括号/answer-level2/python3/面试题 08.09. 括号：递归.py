32ms

```python []
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        def f(l, r, s):
            l == r == n and ans.append(s)
            l < n and f(l + 1, r, s + '(')
            r < l and f(l, r + 1, s + ')')
        f(0, 0, '')
        return ans
```
```python []
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def f(l, r, s):
            l == r == n and (yield s)
            l < n and (yield from f(l + 1, r, s + '('))
            r < l and (yield from f(l, r + 1, s + ')'))
        return [*f(0, 0, '')]
```
```python []
class Solution:
    def generateParenthesis(self, n: int, l=0, r=0, s='') -> List[str]:
        return [
            *(l == r == n and (s, ) or ()),
            *(l < n and self.generateParenthesis(n, l + 1, r, s + '(') or ()),
            *(r < l and self.generateParenthesis(n, l, r + 1, s + ')') or ())
        ]
```
