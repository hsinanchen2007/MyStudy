
```python []
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if nums:
            half = len(nums) // 2
            root = TreeNode(nums[half])
            root.left = self.sortedArrayToBST(nums[: half])
            root.right = self.sortedArrayToBST(nums[half + 1: ])
            return root
```