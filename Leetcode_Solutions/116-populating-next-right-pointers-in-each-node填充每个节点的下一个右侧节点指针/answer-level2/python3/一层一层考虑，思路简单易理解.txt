
```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return root
        stack = [[root]]
        while stack:
            next_level = []
            cur_node = stack.pop()
            if len(cur_node)>1:
                for i in range(len(cur_node)-1):
                    cur_node[i].next = cur_node[i+1]
                    if cur_node[i].left:
                        next_level.append(cur_node[i].left)
                    if cur_node[i].right:
                        next_level.append(cur_node[i].right)
                if cur_node[-1].left:
                    next_level.append(cur_node[-1].left)
                if cur_node[-1].right:
                    next_level.append(cur_node[-1].right)
            else:
                if cur_node[-1].left:
                    next_level.append(cur_node[-1].left)
                if cur_node[-1].right:
                    next_level.append(cur_node[-1].right)
            if next_level:
                stack.append(next_level)
        return root
                    
            
```