跟官方题解思路相同
返回时直接return

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def helper(root):
            nonlocal max_sum
            if root is None:
                return 0
            left_gain = helper(root.left)
            right_gain = helper(root.right)
            max_sum = max(root.val+left_gain+right_gain,max_sum)
            return max(left_gain+root.val,right_gain+root.val,root.val,0)
        max_sum = float("-inf")
        helper(root)
        return max_sum
```
