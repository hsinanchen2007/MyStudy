```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val, next, random):
        self.val = val
        self.next = next
        self.random = random
"""
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        return copy.deepcopy(head)
```
- 内置函数
```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val, next, random):
        self.val = val
        self.next = next
        self.random = random
"""
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        d, node = {None: None}, head
        
        while node:
            d[node] = Node(node.val, None, None)
            node = node.next
        
        node = head
        while node:
            d[node].next = d[node.next]
            d[node].random = d[node.random]
            node = node.next
        
        return d[head]
```
- 难点在于创建节点的时候需要指向未创建的节点
- 遍历俩遍可有效解决，用字典记录对应的节点，然后依靠原来的链表来遍历新链表，第一次遍历未知的节点置 None，第二次再把已经创建的节点改上去
- 链表也是图，133题的dfs解法同样可行