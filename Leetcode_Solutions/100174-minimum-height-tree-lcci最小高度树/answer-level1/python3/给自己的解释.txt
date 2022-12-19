### 解题思路
采用递归的方式进行构建二叉树
在此题中 根节点 为中位数 因为数组已经是经过排序的
然后根据中位数分为两个数组

在此递归 左边数组再过一遍这个函数 找出一个节点 再根据这个节点分为两个数组
右边同理
一直递归
直到不能再二分数组

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
        if not len(nums):
            return 
        mid = len(nums) // 2
        root = TreeNode(nums[mid])
        root.left = self.sortedArrayToBST(nums[: mid])
        root.right = self.sortedArrayToBST(nums[mid + 1: ])
        
        return root 

```