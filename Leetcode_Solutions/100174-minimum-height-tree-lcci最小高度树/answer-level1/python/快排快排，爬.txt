
### 代码
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if not nums:return None
        mid = len(nums)//2
        res = TreeNode(nums[mid])
        res.left = self.sortedArrayToBST(nums[:mid])
        res.right = self.sortedArrayToBST(nums[mid+1:])
        return res
```