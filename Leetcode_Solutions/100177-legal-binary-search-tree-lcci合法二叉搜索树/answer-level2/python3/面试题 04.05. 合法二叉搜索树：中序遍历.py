
```python []
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        vals, f = [], lambda r: r and (f(r.left) or vals.append(r.val) or f(r.right))
        return f(root) or all(val > vals[i] for i, val in enumerate(vals[1: ]))
```