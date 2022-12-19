### 解题思路
明显冗余计算太多

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        self.count = 0
        def helper(node=root, temp_sum=sum, is_parent=False):
            if not node:
                return
            if node.val == temp_sum:
                self.count += 1
            helper(node.left, temp_sum-node.val, True)
            helper(node.right, temp_sum-node.val, True)
            if is_parent:
                return
            helper(node.left, temp_sum, False)
            helper(node.right, temp_sum, False)
        helper()
        return self.count


```