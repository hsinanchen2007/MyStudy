```python
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        # use dfs
        # end-up condition: l == 0 and r == 0
        # l > 0: l -- and add '('
        # r > l: r -- and add ')'

        res = []
        def generate_pairs(l, r, pairs):
            if l == 0 and r == 0: res.append(pairs)
            if l > 0:
                generate_pairs(l - 1, r, pairs + '(')
            if r > l:
                generate_pairs(l, r - 1, pairs + ')')
        generate_pairs(n, n, '')
        return res
```