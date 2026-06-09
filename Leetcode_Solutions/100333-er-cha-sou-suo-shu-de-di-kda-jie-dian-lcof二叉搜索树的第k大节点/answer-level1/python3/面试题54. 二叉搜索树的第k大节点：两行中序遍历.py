
```python []
class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        a, f = [], lambda r: r and (f(r.left) or a.append(r.val) or f(r.right))
        return f(root) or a[-k]
```