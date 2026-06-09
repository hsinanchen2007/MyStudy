```
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None: return True
        def match(l,r):
            if not l and not r: return True
            if not l or not r: return False
            return l.val==r.val and match(l.left,r.right) and match(l.right,r.left)
        return match(root.left,root.right)
```
