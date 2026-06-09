### 解题思路
遍历中记录前一个结点，修改左右指针。遍历完之后，再修改一下第一个结点和最后一个结点的指针。

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
        if root is None:
            return root

        pre = head = Node(None)

        stack = []
        node = root
        while node or stack:
            if node:
                stack.append(node)
                node = node.left
            else:
                node = stack.pop()
                node.left = pre
                pre.right = node
                pre = node
                node = node.right

        pre.right = head.right
        head.right.left = pre

        return head.right

```