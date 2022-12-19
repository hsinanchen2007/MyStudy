### 解题思路
此处撰写解题思路

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
        #学习自labuladong 
        #陷阱: 只比较根、左子树根、右子树根.
        #解决精髓: 用helper函数, 加参数递归: 
        #    右子树以root为min 
        #    左子树以root为max
        def helper(root,min,max):
            if not root: return True
            if min and root.val <= min.val: return False
            if max and root.val >= max.val: return False
            return helper(root.left, min, root) and helper(root.right, root, max)
        return helper(root,None,None)

```