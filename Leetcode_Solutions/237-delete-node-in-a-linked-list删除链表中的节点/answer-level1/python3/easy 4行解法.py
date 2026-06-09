### 解题思路
将这个节点的值赋为next节点的值,然后这个节点的next指向next.next,最后释放next节点
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def deleteNode(self, node):
        next=node.next
        node.val=next.val
        node.next=next.next
        next=None
```