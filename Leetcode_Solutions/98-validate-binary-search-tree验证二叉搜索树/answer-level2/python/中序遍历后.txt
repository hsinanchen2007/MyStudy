
```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def is_increasing(nums):
            for i in range(len(nums) - 1):
                if nums[i + 1] <= nums[i]:
                    return False
            return True

        def helper(node, res):
            if not node:
                return []
            
            if node.left:
                helper(node.left, res)

            res.append(node.val)

            if node.right:
                helper(node.right, res)

        res = []
        helper(root, res)
        return is_increasing(res)
```