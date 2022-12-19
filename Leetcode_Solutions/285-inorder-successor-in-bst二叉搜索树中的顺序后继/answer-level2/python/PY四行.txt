```
class Solution:
    def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
        if root:
            if root.val>p.val:
                return self.inorderSuccessor(root.left,p) or root
            return self.inorderSuccessor(root.right,p)

```
