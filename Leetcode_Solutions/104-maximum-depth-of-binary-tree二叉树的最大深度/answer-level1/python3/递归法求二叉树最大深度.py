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
        def helper(node, level):
            if node is None:
                return level
            return max(helper(node.left, level+1), helper(node.right, level+1))
        return helper(root, 0)

        
```