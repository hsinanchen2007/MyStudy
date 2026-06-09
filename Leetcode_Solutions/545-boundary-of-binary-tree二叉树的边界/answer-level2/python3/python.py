```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def boundaryOfBinaryTree(self, root: TreeNode) -> List[int]:
        left_b, right_b, leaves = [], [], []
        def get_left_boundary(node):
            if not node: return
            left_b.append(node.val)
            if node.left: get_left_boundary(node.left)
            else: get_left_boundary(node.right)

        def get_right_boundary(node):
            if not node: return
            right_b.append(node.val)
            if node.right: get_right_boundary(node.right)
            else: get_right_boundary(node.left)
        
        def get_leaves(node):
            if not node: return None
            if not node.left and not node.right:
                leaves.append(node.val)
                return
            get_leaves(node.left)
            get_leaves(node.right)

        if root == None: return []
        if not root.left and not root.right: return [root.val]
        if root.left:
            get_left_boundary(root.left)
            if len(left_b) > 0: left_b.pop()
        if root.right:
            get_right_boundary(root.right)
            if len(right_b) > 0: right_b.pop()
        get_leaves(root)
        return [root.val] + left_b + leaves + right_b[::-1]
```