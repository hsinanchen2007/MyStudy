# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        """
           核心在于二叉树的深度遍历
        """
        if len(nums) == 0:
            return None
        
        if len(nums) == 1:
            return TreeNode(nums[0])
        
        # 单独把root_node保存下来用于返回
        root_max_index = self.find_big_data_index(nums)
        root_node = TreeNode(nums[root_max_index])
        
        def helper(nums_: List[int]):
            # 深度遍历的停止条件
            if len(nums_) == 0:
                return None
            if len(nums_) == 1:
                return TreeNode(nums_[0])
            tmp_max_index = self.find_big_data_index(nums_)
            tmp_node = TreeNode(nums_[tmp_max_index])
            # 寻找当前节点的左孩子
            tmp_node.left = helper(nums_[:tmp_max_index])
            # 寻找当前节点的右孩子
            tmp_node.right = helper(nums_[tmp_max_index+1:])
            
            return tmp_node
            
        root_node.left = helper(nums[:root_max_index])
        root_node.right = helper(nums[root_max_index+1:])
        
        return root_node
    
    
    def find_big_data_index(self, nums: List[int]):
        """
           直接一个循环找到最大值的索引
        """
        max_value = float('-inf')
        max_index = 0
        for i in enumerate(nums):
            if i[1] > max_value:
                max_value = i[1]
                max_index = i[0]
        
        return max_index