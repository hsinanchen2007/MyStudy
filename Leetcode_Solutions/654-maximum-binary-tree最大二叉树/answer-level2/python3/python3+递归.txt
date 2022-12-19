### 解题思路
递归一下，你就知道(●ˇ∀ˇ●)

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
        if len(nums) == 1:
            return TreeNode(nums[0])
        a = nums.index(max(nums))
        cur = TreeNode(nums[a])
        if a != 0:
            cur.left = self.constructMaximumBinaryTree(nums[:a])
        if a != len(nums)-1:
            cur.right = self.constructMaximumBinaryTree(nums[a+1:])
        return cur


```