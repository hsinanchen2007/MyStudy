```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        node = root
        parent = None
        flag = 0
        if root == None: return root
        if not root.left and not root.right:
            if root.val == key: return None
        while node.val != key:
            parent = node
            if node.val < key:
                node = node.right
                flag = 1
            elif node.val > key:
                node = node.left
                flag = 2
            if not node: return root
        
        if node.right:
            t = node.right.left
            node.val = node.right.val
            node.right = node.right.right
            if node.left:
                left = node.left
                while left.right:
                    left = left.right
                left.right = t
            else:
                node.left = t
        elif node.left:
            t = node.left.right
            node.val = node.left.val
            node.left = node.left.left
            node.right = t
        else:
            if flag == 1:   parent.right = None
            elif flag == 2: parent.left = None
        return root	
```