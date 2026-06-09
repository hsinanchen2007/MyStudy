### 解题思路
设定上下限，左右递归求解。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        if root == None:
            return True
        


        def check(root, low, high):
            if root == None:
                return True
            if root.val <= low or root.val >= high:
                return False
            else:
                return check(root.left, low, root.val) and check(root.right, root.val, high)
        

        return check(root, -float('inf'), float('inf'))
```