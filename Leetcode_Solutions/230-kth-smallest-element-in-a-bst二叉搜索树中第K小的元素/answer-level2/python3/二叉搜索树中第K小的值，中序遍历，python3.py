### 解题思路
先对二叉树进行中序遍历，将节点值存入列表midorder
返回列表midorder中的第k个值

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        midorder = []
        def mid(bnode):
            if not bnode:
                return
            mid(bnode.left)
            midorder.append(bnode.val)
            mid(bnode.right)
        mid(root)
        return midorder[k-1]

```