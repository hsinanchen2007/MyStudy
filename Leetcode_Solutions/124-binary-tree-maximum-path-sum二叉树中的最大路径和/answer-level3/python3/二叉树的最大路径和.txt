### 解题思路
递归思想，用一个变量self.ans来存储最大值，使用self.ans = max(self.ans, left + right + root.val)更新最大值，递归返回的是节点单边的的最大值。

### 代码
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        self.ans = float('-inf') 
        self.max_gain(root)
        return self.ans

    def max_gain(self, root):           
        if not root:
            return 0
        left = max(0, self.max_gain(root.left))
        right = max(0, self.max_gain(root.right))
        self.ans = max(self.ans, left + right + root.val)
        return max(left, right) + root.val
```
