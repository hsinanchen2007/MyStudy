```
class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        def rever(node):
            if node is None:
                return
            node.left,node.right=node.right,node.left
            rever(node.left)
            rever(node.right)
        rever(root)
        return root
```
