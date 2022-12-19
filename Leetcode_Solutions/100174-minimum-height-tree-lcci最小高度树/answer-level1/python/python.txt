递归，构建一个函数求出，对于一个给定数组返回最小高度的树，每次结点取数组中间的值

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
        if not nums:
            return None
        mid=len(nums)/2
        array_l=nums[:mid]
        array_r=nums[mid+1:]
        root=TreeNode(nums[mid])
        root.left=self.sortedArrayToBST(array_l)
        root.right=self.sortedArrayToBST(array_r)
        return root
            
```