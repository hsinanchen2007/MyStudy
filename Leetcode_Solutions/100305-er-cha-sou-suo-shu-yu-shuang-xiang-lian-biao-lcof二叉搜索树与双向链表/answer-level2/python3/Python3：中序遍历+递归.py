### 解题思路
二叉搜索树的中序遍历是递增的，可以把递归过程中的节点保存在列表中。
1. 储存当前节点前，当前节点是列表最后一个节点的右节点。
2. 储存当前节点后，当前节点在列表中就变成了倒数第一个节点，倒数第一个节点的左节点是倒数第二个节点。

### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""
class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if not root:
            return None

        stack = []
        def helper(node):
            if not node:
                return
            if node.left:
                helper(node.left)

            if stack:
                stack[-1].right = node
            stack.append(node)
            if len(stack) >= 2:
                stack[-1].left = stack[-2]

            if node.right:
                helper(node.right)

        helper(root)
        stack[0].left = stack[-1]
        stack[-1].right = stack[0]
        # 以下为测试
        # head = stack[0]
        # def print_(node, dir):
        #     count = 0
        #     while node and count <= 10:
        #         print(node.val)
        #         count += 1
        #         node = node.left if dir == 'left' else node.right
        # # print_(head, 'left')
        # # print_(head, 'right')
        return stack[0]
```