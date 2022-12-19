### 解题思路
python需要在父节点上进行操作，所以判断稍微麻烦一点。通过父节点的左右子节点判断，同时返回给再上一层的节点一个结果。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pruneTree(self, root: TreeNode) -> TreeNode:
        def prune(node: TreeNode):
            if not node:
                return 0
            if not node.right and not node.left:
                return node.val
            if prune(node.left) ==0:
                node.left = None
            if prune(node.right) ==0:
                node.right = None
            return prune(node.left) or prune(node.right) or node.val
        prune(root)
        return root
```