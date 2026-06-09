### 解题思路
利用两个指针分别指向分节点与当前节点，减少判断

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        
        vnode = TreeNode(val)
        if not root: return vnode
        else:
            pre, node = None, root
            while node:
                pre = node
                node = node.left if val < node.val else node.right

            if pre.val < val: pre.right = vnode
            else: pre.left = vnode
            return root

```