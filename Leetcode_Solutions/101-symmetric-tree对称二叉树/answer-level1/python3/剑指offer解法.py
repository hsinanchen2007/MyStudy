```
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        return self.traversing_binary_tree(root, root)


    def traversing_binary_tree(self, root1, root2):
        if root1 == None and root2 == None:
            return True

        if root1 == None or root2 == None:
            return False
        
        if root1.val != root2.val:
            return False
        
        return self.traversing_binary_tree(root1.left, root2.right) and self.traversing_binary_tree(root1.right, root2.left)
```
