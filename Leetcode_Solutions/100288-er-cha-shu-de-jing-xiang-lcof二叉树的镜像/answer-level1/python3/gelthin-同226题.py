### 解题思路
同[主站226题](https://leetcode-cn.com/problems/invert-binary-tree/)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        if root == None:
            return root

        root.left, root.right = self.mirrorTree(root.right), self.mirrorTree(root.left)
        return root
```