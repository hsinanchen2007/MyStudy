### 解题思路
iterate travesal还是需要练习的

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root or root.val == val:
            return root 
            
        stack = []
        node = root
        while True:
            while node:
                stack.append(node)
                node = node.left
            if len(stack) == 0:
                return None
            node = stack.pop()
            if node.val == val:
                return node
            node = node.right

        return None
```