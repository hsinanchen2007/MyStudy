### 解题思路
先找到数组的中间值。然后左右两边分割

设立基本的返回情况,分别为长度为0,1,或者2 的时候

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
        if len(nums) == 0:
            return None
        if len(nums) == 1:
            return TreeNode(nums[0])
        if len(nums) == 2:
            res = TreeNode(nums[1])
            res.left = TreeNode(nums[0])
            return res
        mid = len(nums) // 2
        res = TreeNode(nums[mid])
        res.left = self.sortedArrayToBST(nums[:mid])
        res.right = self.sortedArrayToBST(nums[mid+1:])

        return res
```