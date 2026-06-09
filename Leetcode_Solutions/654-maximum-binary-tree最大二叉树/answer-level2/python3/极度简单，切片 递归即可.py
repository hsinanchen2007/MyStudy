### 解题思路



### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        if not nums: return []
        def dfs(nums):
            if not nums:return 
            max_index = nums.index(max(nums))
            root = TreeNode(nums[max_index])
            root.left = dfs(nums[:max_index])
            root.right = dfs(nums[max_index+1:])
            return root
        return dfs(nums)

```