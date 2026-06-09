### 解题思路
别问我为什么，我也不知道，记住吧。。。()
[[https://www.bilibili.com/video/av77379321?from=search&seid=4893971092726147174]()]()
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
        if root is None:
            return 0
        else:
            return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1
```