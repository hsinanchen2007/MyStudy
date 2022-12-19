### 解题思路
通过迭代函数把每棵树的子树值互换，并进入下一次迭代

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return
        node = TreeNode(0)
        self.make(root, node)
        return node

    def make(self, root: TreeNode, n: TreeNode):
        n.val = root.val
        if root.left:
            n.right = TreeNode(0)
            self.make(root.left, n.right)
        if root.right:
            n.left = TreeNode(0)
            self.make(root.right, n.left)
```