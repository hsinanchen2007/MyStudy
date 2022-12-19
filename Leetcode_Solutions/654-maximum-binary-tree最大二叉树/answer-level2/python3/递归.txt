```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
	def constructMaximumBinaryTree(self, nums):
		nums_length=len(nums)
		max_num=max(nums)
		max_index=nums.index(max_num)
		root=TreeNode(max_num)
		root.left=self.constructMaximumLeftBinaryTree(root.left,nums[:max_index],0,max_index)
		root.right=self.constructMaximumRightBinaryTree(root.right,nums[max_index+1:],max_index+1,nums_length)
		return root
	def constructMaximumLeftBinaryTree(self,root,nums,left,right):
		if left==right:
			return
		else:
			return self.constructMaximumBinaryTree(nums)
	def constructMaximumRightBinaryTree(self,root,nums,left,right):
		if left==right:
			return
		else:
			return self.constructMaximumBinaryTree(nums)
```
