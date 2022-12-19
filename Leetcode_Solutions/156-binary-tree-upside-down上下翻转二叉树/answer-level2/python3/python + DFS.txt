```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def upsideDownBinaryTree(self, root: TreeNode) -> TreeNode:
    #    4     5
    #     \   /
    #       2    
    #      / \ 
    #     3   1
        if root == None: return None
        def dfs(node):
            if not node.left and not node.right: return node
            res = dfs(node.left)
            node.left.right = node
            node.left.left = node.right
            return res
        tempRoot = root # process root particularly.
        root = dfs(root)
        tempRoot.left, tempRoot.right = None, None
        return root
```