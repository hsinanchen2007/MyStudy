### 解题思路
反序中序遍历实现转化

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        stack = []
        node = root
        temp = float('inf')
        while node or stack:
            if node:
                stack.append(node)
                node = node.right
            else:
                node = stack.pop()
                if temp == float('inf'):
                    temp = node.val
                else:
                    node.val += temp
                    temp = node.val
                node = node.left
        return root

```