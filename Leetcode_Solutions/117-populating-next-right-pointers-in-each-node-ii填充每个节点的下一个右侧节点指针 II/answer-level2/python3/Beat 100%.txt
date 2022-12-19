用`cur_level`和`next_level`那一套来做层次遍历。

感觉这个题就是为了层次遍历来设计的呀



```
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution(object):
    def connect(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        if not root:
            return
        res,cur_level = [],[root]
        while cur_level:
            next_level = []
            for node in cur_level:
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
            res.append(cur_level)
            cur_level = next_level
        
        for cur_level in res:
            for i in range(len(cur_level)-1):
                cur_level[i].next = cur_level[i+1]
        return root
```
