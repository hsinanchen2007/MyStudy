### 解题思路
前序遍历+排序

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findSecondMinimumValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        nums=[]
        if not root:
            return root
        def inorderTraversal(node):
            if not node:
                return
            nums.append(node.val)
            inorderTraversal(node.left)
            inorderTraversal(node.right)
        inorderTraversal(root)#（1）前序遍历
        nums.sort()#（2）排序
        #(3)使用for循环判断是否存在第二小的数，而不能使用nums[1]
        for i in range(1,len(nums)):
            if nums[i]>nums[i-1]:
                return nums[i]
        return -1
```