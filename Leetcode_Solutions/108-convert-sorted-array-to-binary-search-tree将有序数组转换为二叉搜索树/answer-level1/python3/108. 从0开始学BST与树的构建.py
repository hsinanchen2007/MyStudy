### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if not nums:
            return None
        
        mid = len(nums) // 2
        root = TreeNode(nums[mid])\

        left = nums[:mid]
        right = nums[mid+1:]

        root.left = self.sortedArrayToBST(left)
        root.right = self.sortedArrayToBST(right)

        return root
```