```
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def helper(root: TreeNode, lower=float('-inf'), upper=float('inf')):
            if not root: return True
            if lower >= root.val or root.val>=upper:
                return False
            return helper(root.left,lower,root.val) and helper(root.right, root.val,upper)
        
        return help(root)
```
