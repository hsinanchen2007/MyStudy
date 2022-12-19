### 解题思路
三步曲，1.取其中一颗树，先把当前值算出来，2.然后分治左右子树，3.回传值从新赋值左右子树

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        if not t1 or not t2:
            return t1 or t2
        
        t1.val = t1.val + t2.val

        left = self.mergeTrees(t1.left, t2.left)
        right = self.mergeTrees(t1.right, t2.right)
        
        t1.left = left
        t1.right = right

        return t1

```