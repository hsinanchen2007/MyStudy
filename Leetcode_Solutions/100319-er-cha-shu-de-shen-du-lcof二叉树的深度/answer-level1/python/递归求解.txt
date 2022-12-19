### 解题思路
递归求解

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def max_depth(node):
            if not node:
                return 0
            return  max(max_depth(node.left),max_depth(node.right))+1
        return max_depth(root)
```