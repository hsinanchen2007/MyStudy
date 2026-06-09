### 解题思路
此处撰写解题思路

### 代码

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


from collections import deque
class Solution:
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        levels = []
        if not root:
            return levels
        cur_layer = [root,]#deque([root,])
        next_layer = []
        while cur_layer:
            levels.insert(0,[])#levels.append([])
            for node in cur_layer:
                levels[0].append(node.val) #this change from levels[-1].append(node.val)
                if node.left:
                    next_layer.append(node.left)
                if node.right:
                    next_layer.append(node.right)
            cur_layer = next_layer
            next_layer = []
        return levels
```