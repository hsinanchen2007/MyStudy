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
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        #迭代
        if root is None:
            return 0
        def depth(root):
            if root is None:
                return 0
            return max(depth(root.left),depth(root.right))+1

        res=[]
        if not root :
            return 0
        stack=[root]
        while stack:
            node=stack.pop(0)
            res.append(depth(node.left)+depth(node.right))
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
        return max(res)

```