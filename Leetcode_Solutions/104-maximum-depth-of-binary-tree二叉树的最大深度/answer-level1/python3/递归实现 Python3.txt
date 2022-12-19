```python [3]
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        nLeft = self.maxDepth(root.left)
        nRight = self.maxDepth(root.right)
        if (nLeft > nRight):
            return nLeft+1
        else:
            return nRight+1
```
