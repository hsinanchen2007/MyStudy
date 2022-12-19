### 解题思路

构造两个递归函数，一个递归函数用于判断一个节点是否是另一个节点的字节点，另一个递归用于后序遍历整个二叉树。

### 代码

```python3
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root:
            return None
        left = self.lowestCommonAncestor(root.left, p, q)
        if self.is_children(left, p) and self.is_children(left, q):
            return left
        right = self.lowestCommonAncestor(root.right, p, q)
        if self.is_children(right, p) and self.is_children(right, q):
            return right
        return root

    def is_children(self, root: 'TreeNode', p: 'TreeNode') -> bool:
        if not root:
            return False
        return root.val == p.val or self.is_children(root.left, p) or self.is_children(root.right, p)
```