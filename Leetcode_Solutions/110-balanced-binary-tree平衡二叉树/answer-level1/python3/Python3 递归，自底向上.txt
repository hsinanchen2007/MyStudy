### 解题思路
此处撰写解题思路

递归，从下往上计算子树的深度，并进行判断
时间复杂度O(n)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    isBBT = True
    def isBalanced(self, root: TreeNode) -> bool:
        self.countDepth(root)
        return self.isBBT

    def countDepth(self, node):
        if node == None:
            return 0
        leftDepth = self.countDepth(node.left) + 1
        rightDepth = self.countDepth(node.right) + 1
        if abs(leftDepth - rightDepth) > 1:
            self.isBBT = False
        return max(leftDepth, rightDepth)
```