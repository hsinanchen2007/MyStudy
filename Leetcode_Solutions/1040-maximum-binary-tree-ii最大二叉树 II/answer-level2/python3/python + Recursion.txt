```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def insertIntoMaxTree(self, root: TreeNode, val: int) -> TreeNode:
        # if val > node.val =? TreeNode(val) = parent of node
        # [1, 4, 2, 3, 5]
        # [2, 1, 5, 4, 3]
        # Tree => A => A.append(val) => contruct Tree
        # find the first one larger then it
        # if exists:
        # if not exists
        min_diff = float('inf')
        larger_node = None
        def traverse(node, val):
            nonlocal min_diff, larger_node
            if not node or node.val < val: return
            if node.val - val < min_diff:
                larger_node = node
                min_diff = node.val - val
            traverse(node.right, val)
        traverse(root, val)
        new_node = TreeNode(val)
        if larger_node == None:
            new_node.left = root
            return new_node
        else:
            new_node.left = larger_node.right
            larger_node.right = new_node
            return root
```