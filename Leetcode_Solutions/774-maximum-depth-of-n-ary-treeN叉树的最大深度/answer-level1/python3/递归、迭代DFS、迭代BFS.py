```
"""
# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution:
    def maxDepth(self, root: 'Node') -> int:
        '''递归'''
        if root is None:
            return 0
        children_depth = [self.maxDepth(node) for node in root.children]
        if children_depth:
            return max(children_depth) + 1
        
        '''迭代DFS'''
        if root is None:
            return 0
        stack = [(1, root)]
        max_depth = 1
        while stack:
            cur_depth, node = stack.pop()
            max_depth = max(max_depth, cur_depth)
            for i in range(len(node.children)-1, -1, -1):
                if node.children[i]:
                    stack.append((cur_depth+1, node.children[i]))
        return max_depth
                    
        
        
        '''迭代BFS'''
        if root is None:
            return 0
        
        queue = [root]
        depth = 1
        
        while queue:
            que_size = len(queue)
            next_level = []
            for _ in range(que_size):
                node = queue.pop(0)
                for child in node.children:
                    if child:
                        queue.append(child)
                        next_level.append(child)
            if next_level != []:
                depth += 1
        return depth
        
        
```
也是参照了别人的写法，做一下总结吧。