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
        

        def max_node(nums:List[int],start:int,end:int):
            max_num = max(nums[start:end])
            return nums.index(max_num)


        def build_tree(nums:List[int],start:int,end:int):
            if start>=end:
                return None
                
            root_index = max_node(nums,start,end)
            root = TreeNode(nums[root_index])
            root.left = build_tree(nums,start,root_index)
            root.right = build_tree(nums,root_index+1,end)
            return root

        return build_tree(nums,0,len(nums))
        

         
```