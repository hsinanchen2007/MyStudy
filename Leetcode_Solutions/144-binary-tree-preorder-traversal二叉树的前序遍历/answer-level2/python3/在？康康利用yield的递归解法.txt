### 解题思路
yield关键字作用可以理解为返回一个值，并继续执行余下代码的return

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:

        def preorder(root):
            if root:
                yield root.val
                yield from preorder(root.left)
                yield from preorder(root.right)
        

        return list(preorder(root))
```