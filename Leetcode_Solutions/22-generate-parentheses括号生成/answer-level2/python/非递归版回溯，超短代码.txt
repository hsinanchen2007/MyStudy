```
class Solution(object):
    def generateParenthesis(self, N):
        nodes = [('', 0, 0)]
        res = []
        while nodes:
            n = nodes.pop()
            if n[1] == N:
                res.append(n[0]+')'*(n[1] - n[2]))
                continue
            if n[1] < N:
                nodes.append((n[0]+'(', n[1]+1, n[2]))
            if n[2] < n[1]:
                nodes.append((n[0]+')',n[1], n[2]+1))
        return res
```

