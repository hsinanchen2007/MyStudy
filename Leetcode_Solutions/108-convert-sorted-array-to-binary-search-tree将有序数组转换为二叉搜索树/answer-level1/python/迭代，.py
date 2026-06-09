### 解题思路
找到当前数组的中间位置作为根节点

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        ###递归
        ###优先选择当前列表的中间位置的左边的元素
        ####（如果当前列表有奇数个元素就是选中间的元素）为根节点
        if len(nums)==0:return None
        def helper(nums):
            RtId=len(nums)//2-1 if len(nums)%2==0 else len(nums)//2
            Root=TreeNode(nums[RtId])
            if len(nums)==1:return Root
            if RtId!=0:Root.left=helper(nums[0:RtId])
            Root.right=helper(nums[RtId+1::])
            return Root
        return helper(nums)
        ####迭代，队列（宽度优先遍历，存放当前层的结点地址）
        # from collections import deque
        # QueBnd=deque([0,len(nums)-1])
        # if len(nums)%2==0:Root=TreeNode(nums[len(nums)//2-1])  
        # else: Root=TreeNode(nums[len(nums)//2])
        # QueTree=deque([Root,])
        # while QueBnd:
        #     Len=len(QueBnd)
        #     for idx in range(Len):
        #         Sta=QueBnd.leftpop()
        #         End=QueBnd.leftpop()
        #         LstRot=QueTree.leftpop()
        #         if Sta==End:
        #             ##说明只有一个剩余的元素
        #             Temp=TreeNode(nums[Sta])









            # if len(BndIds)==0:return Root
```