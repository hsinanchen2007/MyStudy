### 解题思路
很明了，如果当前两个节点相等，需要判断递归判断左节点的左孩子和右节点的右孩子，左节点的右孩子和右节点的左孩子，节点说成树也是可以的，返回他们的&。
所以传入两棵树，如果当前树根节点相等了，判断对应子树是否对称，进行&运算
如果不相等，那肯定部队称，直接返回False
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root == None:
            return True
        
        def dfs(left, right):
            if left == None and right == None:
                return True
            if left == None or right == None:
                return False
            if left.val == right.val:
                return dfs(left.left, right.right) and dfs(left.right, right.left)
            else:
                return False
        return dfs(root.left, root.right)
```