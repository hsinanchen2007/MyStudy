### 解题思路
递归 与 非递归

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
# 递归
class Solution:
    def __init__(self):
        self.listHead = None
        self.listTail = None

    def treeToDoublyList(self, root: 'Node') -> 'Node':
        self.convert(root)
        if self.listHead == None:
            return

        self.listHead.left = self.listTail
        self.listTail.right = self.listHead
        return self.listHead

    def convert(self,node):
        if node == None:
            return

        self.convert(node.left)
        if self.listHead == None:
            self.listHead = node
            self.listTail = node
        else:
            self.listTail.right = node
            node.left = self.listTail
            self.listTail = node
        self.convert(node.right)

# 非递归
class Solution:
    def __init__(self):
        self.listHead = None
        self.listTail = None

    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if root == None:
            return

        stack = []
        curr = root
        while(stack or curr):
            while(curr):
                stack.append(curr)
                curr = curr.left
            curr = stack.pop(-1)
            if self.listHead == None:
                self.listHead = curr
                self.listTail = curr
            else:
                self.listTail.right = curr
                curr.left = self.listTail
                self.listTail = curr
            curr = curr.right
        self.listTail.right = self.listHead
        self.listHead.left = self.listTail
        return self.listHead









        
```