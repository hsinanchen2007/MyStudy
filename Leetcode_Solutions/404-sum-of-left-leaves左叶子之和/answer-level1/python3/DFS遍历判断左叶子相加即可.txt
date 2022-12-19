### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.left_cnt = 0

    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        if not root:
            return 0
        if root and root.left and not root.left.left and not root.left.right:
            self.left_cnt += root.left.val
        if root.left:
            self.sumOfLeftLeaves(root.left)
        if root.right:
            self.sumOfLeftLeaves(root.right)
        return self.left_cnt
```