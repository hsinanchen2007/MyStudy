### 解题思路
这个简单递归方法，应该比较好理解，尾递归，
等递归完左右子树，
把right先存一下，
把left接过去，
再把left置空，
然后把存在temp的right接到right后面
```
def flatten(self, root: TreeNode) -> None:
    if root is None:
        return None
    
    self.flatten(root.left)
    self.flatten(root.right)

    temp = root.right
    root.right = root.left
    root.left = None

    while root.right:
        root = root.right
    root.right = temp

```
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flatten(self, root: TreeNode) -> None:
        if root is None:
            return None
        
        self.flatten(root.left)
        self.flatten(root.right)

        temp = root.right
        root.right = root.left
        root.left = None

        while root.right:
            root = root.right
        root.right = temp
        
```