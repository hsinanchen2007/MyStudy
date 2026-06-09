### 解题思路
剑指offer  python3 版本

### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        self.copyNextNode(head)
        self.copyRandomNode(head)
        return self.reconnectNode(head)
    

    def copyNextNode(self,head):
        node = head
        while(node):
            clone = Node(node.val)
            clone.next = node.next
            node.next = clone
            node = clone.next
    
    def copyRandomNode(self,head):
        node = head
        while(node):
            clone = node.next
            if node.random:
                clone.random = node.random.next
            node = clone.next

    def reconnectNode(self,head):
        node = head
        cloneHead = None
        cloneNode = None
        if node:
            cloneHead, cloneNode = node.next, node.next
            node.next = cloneNode.next
            node = node.next

        while(node):
            cloneNode.next = node.next
            cloneNode = cloneNode.next
            node.next = cloneNode.next
            node = node.next
        return cloneHead



        
```