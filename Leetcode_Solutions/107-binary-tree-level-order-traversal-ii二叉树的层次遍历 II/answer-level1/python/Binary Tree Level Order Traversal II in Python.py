```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        result = []
        stack = [root]

        while stack:
            cur_layer_vals = []
            next_layer_notes = []
            
            for node in stack:
                if node:
                    cur_layer_vals.append(node.val)
                    next_layer_notes.extend([node.left, node.right])
            
            if cur_layer_vals:
                result.insert(0, cur_layer_vals)
            
            stack = next_layer_notes
        
        return result
```
