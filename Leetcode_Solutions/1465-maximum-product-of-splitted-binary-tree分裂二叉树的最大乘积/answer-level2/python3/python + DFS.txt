```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxProduct(self, root: TreeNode) -> int:
        # res = max(res, sum_val - (node.val + left_sum + right_sum))
        res = 0
        sum_val = 0
        MOD = 1e9 + 7
        
        def get_sum(node):
            if node == None: return 0
            return node.val + get_sum(node.left) + get_sum(node.right)

        def get_val(node):
            nonlocal res, sum_val
            if node == None: return 0
            val = node.val + get_val(node.left) + get_val(node.right)
            res = max(res, (sum_val - val) * val)
            return val

        sum_val = get_sum(root)
        get_val(root)

        return int(res % MOD)
```