### 解题思路
递归解决，首先递归的出口是nums为空，递归式是找到max_index,左子树为max_index前面的，右子树为max_index后面的，返回root

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
        if not nums:
            return None
        max_num = max(nums)
        max_index = nums.index(max_num)
        root = TreeNode(max_num)
        root.left = self.constructMaximumBinaryTree(nums[: max_index])
        root.right = self.constructMaximumBinaryTree(nums[max_index+1 :])
        return root
```