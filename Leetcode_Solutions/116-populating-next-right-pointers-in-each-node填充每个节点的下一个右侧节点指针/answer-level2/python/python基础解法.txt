### 解题思路
1. 使用迭代利用next属性实现
2. 使用栈来实现bfs

### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        # if not root:
        #     return root
        
        # nodeleft = root
        # while nodeleft.left:
        #     head = nodeleft
        #     while head:
        #         head.left.next = head.right
        #         if head.next:
        #             head.right.next = head.next.left
            
        #         head = head.next
        #     nodeleft = nodeleft.left
        # return root

        if not root:
            return root
        
        stack = [root]
        while stack:
            size = len(stack)
            for i in range(size):
                node = stack.pop(0)
                if i < size -1:
                    node.next = stack[0]
                if node.left:
                    stack.append(node.left)
                if node.right:
                    stack.append(node.right)
        return root

            


```