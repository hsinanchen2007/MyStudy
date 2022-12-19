```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maximumAverageSubtree(self, root: TreeNode) -> float:
        # Time complexity: O(N)
        # Space complexity: O(1)
        res = 0
        def get_average(node):
            nonlocal res
            if node == None: return (0, 0)
            left_cnt, left_sum = get_average(node.left)
            right_cnt, right_sum = get_average(node.right)
            temp_sum = left_sum + node.val + right_sum
            temp_cnt = left_cnt + right_cnt + 1
            res = max(res, temp_sum / temp_cnt)
            return (temp_cnt, temp_sum)
        get_average(root)
        return res
```