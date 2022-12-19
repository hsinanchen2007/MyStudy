### 解题思路
每次入栈同一层结点，并标记深度，依次出栈直到最后一层。

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
        if root is None:
            return 0
            
        stack = [(root, 1)]
        
        while stack:
            node, num = stack.pop(0)
            if node is not None:
                stack.append((node.left, num+1))
                stack.append((node.right, num+1))

        return num-1






















```