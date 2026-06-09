### 解题思路
先层序遍历树，过程中记录下各节点的层次，然后遍历树的每一层，将next指针指向当前层中的下一个节点

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
        if not root:
            return None
        i = 0
        queue = [[root, 1]]
        while i < len(queue):
            if queue[i][0].left:
                queue.append([queue[i][0].left, queue[i][1]+1])
            if queue[i][0].right:
                queue.append([queue[i][0].right, queue[i][1]+1])
            i += 1
        for i in range(len(queue)-1):
            if queue[i+1][1] == queue[i][1]:
                queue[i][0].next = queue[i+1][0]
            else:
                queue[i][0].next = None
        queue[-1][0].next = None
        return queue[0][0]

```