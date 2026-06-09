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
        if root == None : return True
        return self.check(root.left, root.right)

    def check(self, t1, t2):
        ##判断这两个数为镜像
        if not t1 and not t2: return True
        if not t1 or not t2: return False
        if t1.val != t2.val: return False   
        return self.check(t1.left, t2.right) and self.check(t1.right, t2.left)

```