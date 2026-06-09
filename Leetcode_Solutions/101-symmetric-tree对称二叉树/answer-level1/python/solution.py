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
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root == None:
            return True
        queue = []
        queue.append(root.left)
        queue.append(root.right)

        while len(queue) != 0:
            left_node = queue[0]
            queue.pop(0)
            right_node = queue[0]
            queue.pop(0)

            if(left_node == None and right_node == None):
                continue
            if(left_node == None or right_node == None):
                return False
            if(left_node.val != right_node.val):
                return False
            
            queue.append(left_node.left)
            queue.append(right_node.right)
            queue.append(left_node.right)
            queue.append(right_node.left)
        
        return True
```