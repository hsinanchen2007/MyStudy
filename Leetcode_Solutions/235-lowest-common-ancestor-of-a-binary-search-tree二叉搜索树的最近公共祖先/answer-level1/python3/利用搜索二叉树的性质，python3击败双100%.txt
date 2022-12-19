![image.png](https://pic.leetcode-cn.com/6ddde8a3e06b34bddaa20c36635b7f56f048d78f996c7aeab6a7d1f33cb6144a-image.png)

```
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
      if not root: return root
      if (p.val > root.val and q.val < root.val) \
        or (p.val < root.val and q.val > root.val) \
        or p.val == root.val  or q.val == root.val:
        return root
      elif (p.val > root.val and q.val > root.val):
        return self.lowestCommonAncestor(root.right, p, q)
      else:
        return self.lowestCommonAncestor(root.left, p, q)
```
