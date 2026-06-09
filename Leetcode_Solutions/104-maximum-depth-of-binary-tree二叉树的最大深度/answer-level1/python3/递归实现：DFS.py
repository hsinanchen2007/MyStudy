最大深度是数据结构中的常见问题
```
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root == None:
            return 0
        if root.left != None or root.right != None:
            return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))
        else:
            return 1
```