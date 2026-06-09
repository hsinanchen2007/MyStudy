```
class Solution:
    def isValidBST(self, root: TreeNode, left: int = float('-inf'), right: int = float('inf')) -> bool:
        return not root or (left < root.val < right) \
               and self.s_b(root.left, left, root.val) \
               and self.s_b(root.right, root.val, right)
```
