```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root or root.left is root.right: return True
        l, r, i, o = root.left, root.right, TreeNode(0), TreeNode(0)
        if (l and l.val) != (r and r.val): return False
        i.left, i.right, o.left, o.right = l.left, r.right, l.right, r.left
        return self.isSymmetric(i) and self.isSymmetric(o)
```
- 一棵树对称意味着：
	- 左节点=右节点
	- 左节点的左子树与右节点右子树对称
	- 左节点的右子树与右节点左子树对称
- 前三行处理特殊情况：root为None或root无子节点直接返回True，root只有一个子节点或root两个子节点不相等直接返回False
- 第一个条件在前三行处理过了，对于第二和第三个条件，我们分别构造两个假树i(inner)和o(outer)，i代表内假树，对应条件二，o代表外假树，对应条件三。递归内外假树即可