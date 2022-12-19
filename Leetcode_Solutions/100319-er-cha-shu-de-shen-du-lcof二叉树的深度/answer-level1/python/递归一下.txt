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
    def maxDepth(self, root: TreeNode) -> int:
        # 递归实现即可
        if not root:return 0
        depth = max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1
        return depth
```