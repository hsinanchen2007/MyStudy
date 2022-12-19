```
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        
        dic = {root: None}
        def dfs(root):
            if not root: return
            if root.left: dic[root.left] = root
            if root.right: dic[root.right] = root
            dfs(root.left)
            dfs(root.right)
        
        dfs(root)

        ancestor = set()
        while p:
            ancestor.add(p)
            p = dic[p]
        while q not in ancestor:
            q = dic[q]
        return q
```
