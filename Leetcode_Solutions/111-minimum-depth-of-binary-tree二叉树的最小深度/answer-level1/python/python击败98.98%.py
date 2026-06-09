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
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        def res(root):
            if not root.left and not root.right:
                return 1
            if root.right and root.left:
                return 1+min(res(root.left),res(root.right))
            if root.right:
                return 1+res(root.right)
            return 1+res(root.left)
        return res(root)
        
        
            
            
            
            
```