
```python []
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        d = collections.defaultdict(list)
        f = lambda r, i: r and (d[i].append(r.val) or f(r.left, i + 1) or f(r.right, i + 1))
        return f(root, 0) or d.values()
```