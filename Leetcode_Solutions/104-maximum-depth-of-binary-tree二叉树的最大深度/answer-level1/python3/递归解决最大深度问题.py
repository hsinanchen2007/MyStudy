一棵二叉树的最大深度就是它的左子树和右子树的最大深度中大者加一

按照这个思路,便可以按照如下方式实现
```
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        if root.left or root.right:
            return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))
        else:
            return 1
```
