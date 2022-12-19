```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderSuccessor(self, root: TreeNode, p: TreeNode) -> TreeNode:	
        # BST
        # Find the element => 1:
        # if node.right: traverse(node.right)
        # elif node is leftNode: return Parent
        # else: null
        # flag == 1 -> left
        # flag == 2 ->  right
        res = False
        stack = [(root, 0)]
        while stack:
            node, flag = stack.pop()
            if flag == 0:
                stack.append((node, 1))
                if node.left:
                    stack.append((node.left, 0))
            else:
                if res: return node
                if node.val == p.val: res = True
                if node.right:
                    stack.append((node.right, 0))
            
        return None
```