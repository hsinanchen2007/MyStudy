### 解题思路
递归判断左子树和右子树是否符合条件

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        def getHeight(root):
            if not root:
                return 0,True
            left,lf=getHeight(root.left)
            right,rf=getHeight(root.right)
            return max(left,right)+1, lf and rf and abs(left-right)<=1
        return getHeight(root)[1]
        
```