```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lcaDeepestLeaves(self, root: TreeNode) -> TreeNode:
        ans = None
        def get_max_depth(node):
            if node == None: return 0
            else: return max(get_max_depth(node.left), get_max_depth(node.right)) + 1
           
        def dfs(node, depth):
            nonlocal ans, max_depth
            if depth == max_depth: return True
            if node == None: return False
            left, right = dfs(node.left, depth + 1), dfs(node.right, depth + 1)
            if left == True and right == True:  ans = node
            return left or right
        max_depth = get_max_depth(root)
        dfs(root, 0)
        return ans 

    #     1
    #    / \
    #   2   null
    #  / \
    # 3   4
    #  \   \
    #   6   5
```