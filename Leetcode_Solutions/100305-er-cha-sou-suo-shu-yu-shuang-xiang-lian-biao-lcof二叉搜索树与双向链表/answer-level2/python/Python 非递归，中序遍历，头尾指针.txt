注意是循环链表，最后还要连接头尾。
使用2个指针表示链表的头尾，当中序遍历到最左边节点的时候，设置头结点
对于中间的节点，是链表尾部的右节点，同时这个节点的左节点改成链表尾部

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
        stack = []
        if not root: return None
        
        node = root
        last = None
        head = None
        
        while node or stack:
            while node:
                stack.append(node)
                node = node.left
            
            node = stack.pop()
            
            node.left = last
            if head == None:
                head = node
            else:
                last.right = node
                node.left = last
            last = node
            node = node.right
        
        head.left = last
        last.right = head
        
        return head
```
