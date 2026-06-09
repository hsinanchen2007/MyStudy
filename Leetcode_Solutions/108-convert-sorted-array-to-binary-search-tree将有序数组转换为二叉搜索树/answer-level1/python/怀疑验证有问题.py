### 解题思路
退化的也算是平衡吧

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
        # # 通过的解答
        # if not nums:
        #     return None
        # mid = len(nums) >> 1
        # root = TreeNode(nums[mid])
        # root.left = self.sortedArrayToBST(nums[0: mid])
        # root.right = self.sortedArrayToBST(nums[(mid+1):])
        # return root
        if not nums:
            return None
        idx = 0
        flag = len(nums) >> 1
        lt = nums[0:flag]
        rt = nums[(flag + 1):]
        lt_pre = TreeNode(-1)
        rt_pre = TreeNode(-1)
        for i in xrange(len(lt)):
            node = TreeNode(lt[i])
            node.left = lt_pre.left
            lt_pre.left = node
        rt_tmp = None
        for i in xrange(len(rt)):
            node = TreeNode(rt[i])
            if rt_pre.right is None:
                rt_pre.right = node
            if rt_tmp is None:
                rt_tmp = node
            else:
                rt_tmp.right = node
                rt_tmp = rt_tmp.right
        root = TreeNode(nums[flag])
        root.left = lt_pre.left
        root.right = rt_pre.right
        return root
# 平台给的提示
输入:
[0,1,2,3,4,5]
输出
[3,2,4,1,null,null,5,0]
#       3
#      /\
#     2  4
#    /    \
#   1      5
#  /
# 0
预期结果
[3,1,5,0,2,4]
```