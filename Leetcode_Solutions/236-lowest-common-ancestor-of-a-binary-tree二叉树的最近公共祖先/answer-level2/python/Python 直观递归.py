```python
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root or root == p or root == q:  # 如果搜到了节点或者root为空，直接返回
            return root

        left = self.lowestCommonAncestor(root.left, p, q)  # 找左子树有没有
        right = self.lowestCommonAncestor(root.right, p, q)  # 找右子树

        if not left or not right:  # p、q在一侧
            return left or right

        if left and right:  # p、q在两侧
            return root
```

总体思路就是dfs，而且想写短点还可以这样写

```python
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root or root == p or root == q:
            return root

        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)

        return root if left and right else left or right
```