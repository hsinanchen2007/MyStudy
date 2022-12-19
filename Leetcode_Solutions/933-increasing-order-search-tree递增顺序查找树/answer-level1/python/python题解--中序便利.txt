```
class Solution(object):
    def increasingBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        def search(Root):
            if Root:
                search(Root.left)
                Root.left = None
                self.result.right = Root
                self.result = Root
                search(Root.right)
        
        ans = self.result = TreeNode(None)
        search(root)
        return ans.right
```
