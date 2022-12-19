分别比较对称的位置是否为相等树
```
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        return self.isMirror(root, root)
        
    def isMirror(self, leftRoot: TreeNode, rightRoot:TreeNode):
        if leftRoot == None and rightRoot == None:
            return True
        if leftRoot == None or rightRoot == None:
            return False
        if leftRoot.val != rightRoot.val:
            return False
        return self.isMirror(leftRoot.left, rightRoot.right) and self.isMirror(leftRoot.right, rightRoot.left)
```