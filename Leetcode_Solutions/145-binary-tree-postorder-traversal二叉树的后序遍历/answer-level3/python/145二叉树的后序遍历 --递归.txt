### 解题思路
后序遍历：先遍历左孩子，再遍历右孩子，再自身

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        L=[]
        def posr(root):
            if not root:return
            posr(root.left)
            posr(root.right)
            L.append(root.val)
        posr(root)
        return L

```