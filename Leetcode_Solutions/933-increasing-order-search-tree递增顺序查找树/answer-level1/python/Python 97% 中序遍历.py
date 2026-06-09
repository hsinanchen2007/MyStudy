![image.png](https://pic.leetcode-cn.com/47d0e3e7254f3a150c190cc2481c699f3c6819fdc50a0cb0604038b047701818-image.png)

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        stack = []
        def traverse(tree):
            if tree.left:
                traverse(tree.left)
                tree.left = None
            stack.append(tree)
            if tree.right:
                traverse(tree.right)
        traverse(root)
        for i in range(len(stack)-1):
            stack[i].right = stack[i+1]
        return stack[0]
```
