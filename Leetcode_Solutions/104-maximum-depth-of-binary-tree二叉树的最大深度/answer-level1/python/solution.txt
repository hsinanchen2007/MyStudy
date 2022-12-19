### 解题思路
此处撰写解题思路

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
        def getHeight(node):
            if node == None:
                return 0
            left = getHeight(node.left)
            right = getHeight(node.right)
            return max(left,right) + 1
        return getHeight(root)
```