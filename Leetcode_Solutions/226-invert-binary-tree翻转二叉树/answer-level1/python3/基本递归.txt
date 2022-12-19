### 解题思路
一看就知道递归，没啥

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root: return None
        tmp = root.left
        root.left=root.right
        root.right=tmp
        self.invertTree(root.right)
        self.invertTree(root.left)
        return root
        '''
        def dochange(node: TreeNode):
            if not node: return
            tmp = node.left
            node.left = node.right
            node.right=tmp
            dochange(node.left)
            dochange(node.right)
        '''

```