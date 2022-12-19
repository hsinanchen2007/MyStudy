```python []
class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        
        if not root:
            return None
        
        if val < root.val:
            if not root.left:
                return None
            else:
                return self.searchBST(root.left, val)

        elif val > root.val:
            if not root.right:
                return None
            else:
                return self.searchBST(root.right, val)

        else:
            return root
```
