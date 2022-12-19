### 解题思路
每次遍历到的节点放入一个列表中，最后取中间的节点

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        node_list=[]
        while head:
            node_list.append(head)
            head=head.next
        return node_list[len(node_list)//2]
```