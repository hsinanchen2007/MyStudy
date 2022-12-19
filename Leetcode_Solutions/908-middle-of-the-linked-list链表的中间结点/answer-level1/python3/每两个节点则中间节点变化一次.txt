### 解题思路
每两个节点则中间节点变化一次
观察者模式：idx会根据flag的值进行变化

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        idx = head
        flag = -1
        while head:
            if flag == 1:
                idx = idx.next
            flag = -flag
            head = head.next
        return idx
```