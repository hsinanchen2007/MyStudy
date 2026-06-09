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
    def isvalid(self, root, down, up):
        if root is None:
            return 1
        if root.val <= down or root.val >= up:
            return 0
        else:
            return self.isvalid(root.left, down, root.val) and self.isvalid(root.right, root.val, up)
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
       
        return self.isvalid(root, float('-inf'), float('inf'))

```