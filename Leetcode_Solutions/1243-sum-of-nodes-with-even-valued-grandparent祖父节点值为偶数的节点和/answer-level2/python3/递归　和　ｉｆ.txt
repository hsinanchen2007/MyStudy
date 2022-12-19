### 解题思路
IF无敌
当大爷为偶数，判断有没有孙子，有就加
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        global p
        p=0
        def node2x(root):
            global p
            if(root == None or (root.left == None and root.right == None)):
                return
            if(root.val %2 == 0):
                if(root.left != None):
                    if(root.left.right != None):
                        p += root.left.right.val
                    if(root.left.left != None):
                        p += root.left.left.val
                if(root.right != None):
                    if(root.right.right != None):
                        p += root.right.right.val
                    if(root.right.left != None):
                        p += root.right.left.val
            node2x(root.left)
            node2x(root.right)
        node2x(root)
        return p
```