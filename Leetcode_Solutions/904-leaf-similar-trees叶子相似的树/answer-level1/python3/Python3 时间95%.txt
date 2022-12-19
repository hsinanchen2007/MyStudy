```
class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        def helper(root, lst):
            if not root: return
            if not root.left and not root.right:
                lst.append(root.val)
            helper(root.left, lst)
            helper(root.right, lst)
            return lst
        return helper(root1, []) == helper(root2, [])
```
