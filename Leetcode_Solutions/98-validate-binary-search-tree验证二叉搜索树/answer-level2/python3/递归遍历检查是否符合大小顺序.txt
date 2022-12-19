```
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        last = float('-inf')
        def isvalid(root):
            nonlocal last
            if root is None:
                return True
            if isvalid(root.left) == False:
                return False
            if root.val<=last:
                return False
            last = root.val
            if isvalid(root.right) == False:
                return False
            return True
        return isvalid(root)
```
