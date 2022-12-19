### 解题思路
返回除根节点外最小的值或-1

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        if not root or (not root.left and not root.right): return -1
        left, right = root.left.val, root.right.val
        if left == root.val: left = self.findSecondMinimumValue(root.left)
        if right == root.val: right = self.findSecondMinimumValue(root.right)
        if left != -1 and right != -1: return min(left, right)
        if left != -1: return left
        return right
```