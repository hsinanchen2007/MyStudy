
```python []
class Solution:
    def convertBiNode(self, root: TreeNode) -> TreeNode:
        if root:
            ans, f = [], lambda r: r and (f(r.left) or ans.append(r) or f(r.right))
            f(root)
            for i, r in enumerate(ans[1: ]):
                ans[i].left = None
                ans[i].right = r
            ans[-1].left = None
            return ans[0]
```