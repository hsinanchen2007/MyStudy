### 解题思路
遍历二叉树，树的操作中递归是比较方便的一种操作

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
        return max(self.maxDepth(root.left)+1,self.maxDepth(root.right)+1) if root else 0

```