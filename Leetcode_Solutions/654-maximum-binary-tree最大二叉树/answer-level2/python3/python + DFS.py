```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        # Time complexity : O(NlogN => N ** 2)
        def build_tree(l, r):
            if l > r: return None
            max_index = l
            for i in range(l, r + 1):
                if nums[i] > nums[max_index]:
                    max_index = i
            node = TreeNode(nums[max_index])
            node.left = build_tree(l, max_index - 1)
            node.right = build_tree(max_index + 1, r)
            return node
        return build_tree(0, len(nums) - 1)
```