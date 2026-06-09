### 递归
很简单

### 代码
``` python3
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        return self.inorderTraversal(root.left) + [root.val] + self.inorderTraversal(root.right)
```

### 迭代
有root入栈向左走 
没root出栈向右走

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        stk = []
        res = []
        # 有root入栈向左走 没root出栈向右走
        # 因此root or stk
        while root or stk:
            if root:
                # 一直向左走并把节点加入stk
                stk.append(root)
                root = root.left
            else:
                # 走到头了出栈向右走
                top = stk.pop()
                res.append(top.val)
                root = top.right
        
        return res
```