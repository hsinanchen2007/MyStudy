```
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        return 0 if not root else max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1
```
