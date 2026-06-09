### 解题思路
此处撰写解题思路
1. 构造一个队列，然后把树放进去；
2. 层序遍历树结构，把树的左节点指向右节点；同时构造一个中间变量，把右节点指向下一个遍历的左节点；最后一个元素指向NULL；
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
        if root == None:
            return root
        node = root
        stack = [node]
        while len(stack) != 0:
            n = len(stack)
            right = None
            for i in range(n):
                temp = stack.pop(0)
                if i == n - 1:
                    temp.next = None
                if temp.left:
                    if right:
                        right.next = temp.left
                    stack.append(temp.left)
                    stack.append(temp.right)
                    temp.left.next = temp.right
                    right = temp.right
                
        return node
```