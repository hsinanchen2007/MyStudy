### 解题思路
看是否是叶子节点，若是叶子节点则判断sum==0
否则对左右子树进行遍历

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if root == None:
            return False
        sum -=root.val
        if root.left == None and root.right == None:
            return sum==0
        return self.hasPathSum(root.left,sum) or self.hasPathSum(root.right,sum)
            
```