
```python
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root: return 0

        left_height = self.maxDepth(root.left)
        right_height = self.maxDepth(root.right)

        return max(left_height,right_height) + 1
```