### 解题思路
1. bfs
2. 迭代利用next属性，和116思路比较相似，但是需要用pre来刷新每一层级的head

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
        
        # stack = [root]
        # while stack:
        #     size = len(stack)
        #     for i in range(size):
        #         node = stack.pop(0)
        #         if i < size - 1:
        #             node.next = stack[0]
        #         if node.left:
        #             stack.append(node.left)
        #         if node.right:
        #             stack.append(node.right)
        # return root
        
        if not root:
            return root
        head = root
        while head:
            cur = head
            pre = head = None
            while cur:
                if cur.left:
                    if not pre:
                        pre = head = cur.left
                    else:
                        pre.next = cur.left
                        pre = pre.next
                if cur.right:
                    if not pre:
                        pre = head = cur.right
                    else:
                        pre.next = cur.right
                        pre = pre.next
                cur = cur.next
        return root



                    
```