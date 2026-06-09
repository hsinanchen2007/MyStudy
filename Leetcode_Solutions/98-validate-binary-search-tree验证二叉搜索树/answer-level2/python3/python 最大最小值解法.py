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
        def ds(root,mi,ma):
            if root==None:
                return True
            if root.val<=mi or root.val>=ma:
                return False
            return ds(root.left,mi,root.val)&ds(root.right,root.val,ma)
        return ds(root,float("-inf"), float("inf"))


```