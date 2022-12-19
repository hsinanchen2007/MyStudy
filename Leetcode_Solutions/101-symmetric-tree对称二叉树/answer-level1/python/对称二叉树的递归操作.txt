### 解题思路
1.先判断根结点是否存在
2.对左右节点进行判断，这里学到一点就是建立函数来对左右节点进行操作，判断左右节点是否存在。
3.然后对左右子树进行递归操作

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        def dfs(left,right):
            if(left==None and right==None):
                return True
            if(left==None or right==None):
                return False
            if(left.val != right.val):
                return False
            return dfs(left.left,right.right) and dfs(left.right,right.left)
        #用递归函数比较左节点和右节点
        return dfs(root.left,root.right)
        
```