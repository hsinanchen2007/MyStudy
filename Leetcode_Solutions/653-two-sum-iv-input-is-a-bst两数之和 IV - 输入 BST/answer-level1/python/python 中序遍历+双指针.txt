### 解题思路
将题目分解为中序遍历+双指针有序数组求2元素之和等于目标值

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
        nums=[]
        def inorderTraversal(node):
            if not node:
                return
            inorderTraversal(node.left)
            nums.append(node.val)
            inorderTraversal(node.right)
        inorderTraversal(root)#中序遍历
        l,r=0,len(nums)-1
        while l<r:#使用while循环，双指针求解有序数组中，是否存在2个元素的和等于目标值
            SUM=nums[l]+nums[r]
            if SUM==k:
                return True
            elif SUM>k:
                r=r-1
            else:
                l=l+1
        return False
```