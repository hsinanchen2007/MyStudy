```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distributeCoins(self, root: TreeNode) -> int:
        # return the number of move.
        # each coin only has one coin.
       

        # overload = node.val - 1 + left_overload + right_overload
        # move += abs(overload)
        # return overload
        # Time complexity: O(N)
        # Space complexity: O(N): Recursion stack

        ans = 0
        def compute_overload(node): # from bottom to top
            nonlocal ans
            if node == None: return 0
            left_overload = compute_overload(node.left)
            right_overload = compute_overload(node.right)
            overload = node.val - 1 + left_overload + right_overload
            ans += abs(overload)
            return overload
        compute_overload(root)
        return ans
```