```
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        res = None
        def search(n, p, q):
            if n == None or n==p or n==q:
                return n
            l = search(n.left, p, q)
            r = search(n.right, p, q)
            if l and r:
                return n
            return l if l else r

        return search(root, p, q)
```
