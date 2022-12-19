### 递归
思路：比较简单，代码应该一目了然，就是基于二叉搜索树的特点，左边子树的所有值小于右边子树的所有值。如下：
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
# 
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        n = len(nums)
        if n==0:
            return None
        target = n//2
        root = TreeNode(nums[target])
        root.left = self.sortedArrayToBST(nums[0:target])
        root.right = self.sortedArrayToBST(nums[target+1:n])
        return root
```
#### 复杂度分析

__时间复杂度__：每个值访问一次，$O(n)$

__空间复杂度__：二叉树存储空间，$O(n)$