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
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        #
        if len(nums)==0:
            return None
        maxvalue=nums[0]
        temp=0
        for i in range(1,len(nums)):
            if nums[i]>maxvalue:
                maxvalue=nums[i]
                temp=i
        nums1=nums[:temp]
        nums2=nums[temp+1:]
        root=TreeNode(nums[temp])
        root.left=self.constructMaximumBinaryTree(nums1)
        root.right=self.constructMaximumBinaryTree(nums2)
        return root

```