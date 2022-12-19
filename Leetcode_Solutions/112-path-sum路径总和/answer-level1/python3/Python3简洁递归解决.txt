
![image.png](https://pic.leetcode-cn.com/b8fdb5fc64edad78f1f8565e5c63bd1f***baffd2f0bbbda521e105e1ea4b870-image.png)


代码如下：
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if root is None:
            return False
        
        if root.left is None and root.right is None:
            return root.val == sum
        
        return self.hasPathSum(root.left, sum-root.val) or self.hasPathSum(root.right, sum-root.val)
```