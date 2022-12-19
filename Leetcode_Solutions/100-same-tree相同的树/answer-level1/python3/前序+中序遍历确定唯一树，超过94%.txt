```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        
        def preorder(T, nums):
            if not T:
                nums.append(-1) #找到空白点，nums上一定要体现出来，不然不能区分[1,1]和[1,null,1]
                return
            nums.append(T.val)
            preorder(T.left, nums)
            preorder(T.right, nums)

        def midorder(T, nums):
            if not T:
                nums.append(-1)
                return
            midorder(T.left, nums)
            nums.append(T.val)
            midorder(T.right, nums)

        nums1, nums2, nums3, nums4 = [], [], [], []
        preorder(p, nums1)
        preorder(q, nums2)
        midorder(p, nums3)
        midorder(q, nums4)
        if nums1 == nums2:
            if nums3 == nums4:
                return True
        return False
```
中序遍历加上前序遍历或者后序遍历才能唯一确定一颗树