**粗体**### 解题思路
此处撰写解题思路

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
        # 倘若结点为空
        if not root :
            return root
        queue = []
        queue.append(root)
        while queue :
            # 先记录下该层的元素数量,并修改它们的next指针
            n = len(queue)
            for i in range(n) :
                if i + 1 < n :
                    queue[i].next = queue[i + 1]
            # 将下层结点全部入队列,注意queue会发生变化
            for i in range(n) :
                if queue[i].left :
                    queue.append(queue[i].left)
                if queue[i].right :
                    queue.append(queue[i].right)
            queue = queue[n : ]
        return root

```