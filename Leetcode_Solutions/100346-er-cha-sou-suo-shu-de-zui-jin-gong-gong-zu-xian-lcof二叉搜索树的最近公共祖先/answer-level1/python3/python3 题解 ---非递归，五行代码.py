```
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if p.val > q.val: p,q = q, p 
        while root:
            if p.val > root.val: root = root.right
            if q.val < root.val: root = root.left
            if  p.val <= root.val <= q.val : return root
```
