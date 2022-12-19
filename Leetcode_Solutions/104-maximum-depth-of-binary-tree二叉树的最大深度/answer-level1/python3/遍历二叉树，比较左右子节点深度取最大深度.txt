### 解题思路
用递归的方式遍历整棵树，比较左右子节点的深度，取最大深度返回。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        if root.left:
            left = self.maxDepth(root.left)
        else:
            left = 0
        if root.right:
            right = self.maxDepth(root.right)
        else:
            right = 0
        return 1 + max(left,right)

            

```