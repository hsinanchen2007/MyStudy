### 解题思路
也可将判断大小的过程放到遍历时候，节省空间

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
        a = []
        def LDR(root):
            if(not root):
                return
            LDR(root.left)
            a.append(root.val)
            LDR(root.right)
        LDR(root)
        l = len(a)
        for i in range(1,l):
            if(a[i]<=a[i-1]):
                return False
        return True


```