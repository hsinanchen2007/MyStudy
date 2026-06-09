### 解题思路
1. 深搜：找到左子树最大深度，找到右子树最大深度
2. 最大路径：max(leftDepth) + max(rightDepth) + 1
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
        self.res = 1
        def depth(root):
            if not root:
                return 0
            left = depth(root.left)
            right = depth(root.right)
            self.res = max(self.res, left + right + 1)
            return max(left , right) + 1
        depth(root)
        return self.res - 1  

```