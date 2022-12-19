### 解题思路
二叉树最大深度，递归解法

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if not root :
            return 0
        max_deep = 0
        def md(h):
            nonlocal max_deep
            l = 1 + md(h.left) if h.left else 0
            r = 1 + md(h.right) if h.right else 0
            max_deep = max(max_deep,l + r)
            return max(l,r)
        md(root)
        return max_deep
```