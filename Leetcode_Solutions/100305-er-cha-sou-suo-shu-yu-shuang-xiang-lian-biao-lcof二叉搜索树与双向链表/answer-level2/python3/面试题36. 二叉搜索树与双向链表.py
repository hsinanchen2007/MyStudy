
```python []
class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        a, f = [], lambda r: r and (f(r.left) or a.append(r) or f(r.right))
        f(root)
        n = len(a)
        for i, r in enumerate(a):
            r.left, r.right = a[i - 1], a[i + 1 - n]
        return n and a[0] or None
```