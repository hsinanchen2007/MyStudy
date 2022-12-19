```
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root == p:
            return root
        if root == q:
            return root
        if root is None:
            return None
        l = self.lowestCommonAncestor(root.left, p, q)
        r = self.lowestCommonAncestor(root.right, p, q)
        if (l == q and r == p) or (l == p and r == q):
            return root
        if l is not None:
            return l
        if r is not None:
            return r
```
思路很简单，就是看p和q是不是分别在当前子树的左右两边，如果在两边，就返回根节点。否则就在他的左子树或者右子树再进行相同的操作。