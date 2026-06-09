```python
class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        self.ans=0
        def mid(root):
            if not root:
                return
            mid(root.left)           
            if root.left and not root.left.left and not root.left.right:
                self.ans+=root.left.val
            mid(root.right)
        mid(root)
        return self.ans
```
关键是找到定义什么是左叶子，左叶子就是当前节点的左子树，且左子树的左右节点都不存在。于是可以用中序遍历计算。