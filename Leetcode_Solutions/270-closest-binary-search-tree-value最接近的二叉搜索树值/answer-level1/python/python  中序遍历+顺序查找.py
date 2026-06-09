### 解题思路
中序遍历+顺序查找
简单易懂，但是性能不是很高

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def closestValue(self, root, target):
        """
        :type root: TreeNode
        :type target: float
        :rtype: int
        """
        nums=[]
        MIN=float('inf')
        def inorder(node):
            if not node:
                return
            inorder(node.left)
            nums.append(node.val)
            inorder(node.right)
        inorder(root)
        ans=nums[0]
        for i in range(len(nums)):
            cur=abs(nums[i]-target)
            if cur<MIN:
                MIN=cur
                ans=nums[i]
        return ans


```